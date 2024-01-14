//*********************************************************Caesar Cipher*********************************************************//

// Let's learn how to encrypt messages using the Caesar Cipher encryption method.

// Include this library to be able to use the in/output commands like cin and cout.
#include <iostream>

// inlcude this library to use standard definitions like string, int etc. without the (std::) tag.
using namespace std;

// Encrypting a Message is pretty simple.
//  Each letter in your Message gets shifted in the alphabet a specific amount of times depending on the key.
// The key determines how many times the letters are shifted in the alphabet.
// This Method takes your string input and a Integer Key:
string encryptionUsingCeasarCipher(string input, int key)
{
    // First, we sign a value for the encrypted Message.
    string encryptedInput = "";

    // Then, we go through each letter/character in our string input.
    for (char letter : input)
    {
        // We now check if the character is actually a letter of the alphabet.
        if (isalpha(letter))
        {
            // If it is, we check if its upper or lower case with the isupper() function.
            char upperOrLowerCase = isupper(letter) ? 'A' : 'a';

            // static_cast<char> sets the new character as a char.
            // Now we determine the new position of the letter by adding the key to the ASCII characters.
            // Adding %26 insures that our shift stays within the 26 letters of the Alphabet (0 - 25).
            encryptedInput = encryptedInput + static_cast<char>((letter - upperOrLowerCase + key) % 26 + upperOrLowerCase);
        }
        else
        {
            // If the character isn't in the alphabet, we add it as it is.
            encryptedInput = encryptedInput + letter;
        }
    }

    // Finally, we return the encrypted input back. :)
    return encryptedInput;
}

// Encrypting our input had 4 lines of code.
// Decrypting has only 3.  :O
// The idea is simpler, rearrange the letters to their original position again.

// This function takes the encrypted Message and the key used previously for encrypting:
string decryptionOfMessage(string encryptedInput, int key)
{

    // You can define a variable for the decrypted Message.
    string decryptedMessage = "";

    // Here, we use our encryption method again.
    // But this time, instead of adding the Key, we subtract from it.
    // Again, the 26 is the number of letters in the alphabet.
    decryptedMessage = encryptionUsingCeasarCipher(encryptedInput, 26 - key);

    // Finally, we return the decrypted Message. :)
    return decryptedMessage;
}

// In the main function, we have an simple example.
// We want to encrypt the message "Hello"
// We also assign the key "3" to it, which means each letter will shift three times along the alphabet.
// Our new function is used and then we print the encrypted message out.
// Then we decrypt it using the second function, and we also print it out.

// The word "Hello" encrypted becomes "Khoor".
int main()
{

    string wordToEncrypt = "Hello";
    int key = 3;

    string encryptedOutput = encryptionUsingCeasarCipher(wordToEncrypt, key);

    cout << encryptedOutput << endl;

    string decryptedOutput = decryptionOfMessage(encryptedOutput, key);

    cout << decryptedOutput << endl;

    return 0;
}

//And that's it. :D