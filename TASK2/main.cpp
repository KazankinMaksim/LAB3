#include "RouteCipher.h"

void check(const string& text, const string& key)
{
    try {
        string cipherText;
        string decryptedText;
        int keyInt = std::stoi(key);
        try {
            RouteCipher cipher(keyInt); // Используйте keyInt для создания cipher
            cipherText = cipher.encrypt(text); // Шифруйте текст перед его расшифровкой
            decryptedText = cipher.decrypt(cipherText);
            cout<<"Key:"<<key<<endl;
            cout<<"Text:"<<text<<endl;
            cout<<"Encrypted text: "<<cipherText<<endl;
            cout<<"Decrypted text: "<<decryptedText<<endl;
        } catch (const invalid_argument& e) {
            cerr << "Ошибка: " << e.what() << '\n';
        }
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
    cout<<""<<endl;
}



int main()
{
    check("PIXEL","-1");
	cout << "-------------" << endl;
    check("ЯТУТЖИВУ","3");
	cout << "-------------" << endl;
    check("PIXEL","2");
	cout << "-------------" << endl;
    check("12345678выаврпапо","3");
	cout << "-------------" << endl;
	check("","3");
	cout << "-------------" << endl;
    return 0;
}
