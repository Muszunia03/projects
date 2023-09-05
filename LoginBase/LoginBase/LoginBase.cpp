

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//using namespace std;

class User {

private:

    std::string login;
    std::string password;
    bool properlogin= false;
    bool logininfile = false;
    bool properpassword = false;
    bool passwordinfile = false;
public: 
    User() {
        login = "undefined";
        password = "undefined";
    }

    std::string Logowanie() {
        
        SetLogin();
        //SetPassword();
        SetPassword();
        return this->login, this->password;
    }
    std::string SetLogin() {

        std::cout << "Please insert you login: ";
        std::cin >> login;
        LoginInFile();
        return this->login;
       
    }
    
    std::string SetPassword() {

        /*std::cout << "Please insert you password: ";*/
        //std::cin >> password;
        PasswordCheck();
        
        return this->password;

    }
    void PasswordCheck() {

        bool HasLower = false;
        bool HasUpper = false;
        bool HasLength = false;
        bool HasDigit = false;
        //bool PasswordList = false;

        if (this->properlogin == false ) {
            std::cout << "\n";
        }
        else {
        std::cout << "Please insert you password: ";
        std::cin >> password;
        for (int i = 0; i < this->password.length(); i++) {
            if (islower(password[i])) {
                HasLower = true;

            };
            if (isupper(password[i])) {
                HasUpper = true;

            };
            if (password.length() > 7) {
                HasLength = true;

            };
            if (isdigit(password[i])) {
                HasDigit = true;

            };
            /* if (password == "Admin123" || password == "Haslo123" || password == "Gowno123" || password == "1234567") {
                 PasswordList = true;
             }*/
        }
        if (HasLower) {
            std::cout << "has lowercase letter\n";
        }

        if (HasUpper) {
            std::cout << "has uppercase letter\n";
        }
        if (HasDigit) {
            std::cout << "has digit\n";
        }
        if (HasLength) {
            std::cout << "has proper length\n";
        }
        /*if (PasswordList) {
            std::cout << "password is on the list\n";
        }*/
        /////////////////////////////////////////
        if (HasLower == false) {
            std::cout << "does not have lowercase letter\n";
        }

        if (HasUpper == false) {
            std::cout << "does not have uppercase letter\n";
        }
        if (HasDigit == false) {
            std::cout << "does not have digit\n";
        }
        if (HasLength == false) {
            std::cout << "does not have proper length\n";
        }
        /*if (PasswordList == false) {
            std::cout << "password is not on the list\n";
        }*/
        PasswordInFile();

        if (HasDigit && HasLength && HasLower && HasUpper && passwordinfile == true) {

            std::cout << "Password is correct" << std::endl;
            std::cout << "welcome to the server" << std::endl;

        }
        else if (HasDigit == false || HasLength == false || HasLower == false || HasUpper == false) {

            std::cout << "Not all conditions have been met" << std::endl;

        }
        else {

            std::cout << "try again" << std::endl;

        }
    }
    }
    void LoginCheck() {
    
        std::string answer;
        std::string filename;
        std::ifstream newfile;
        std::ofstream insert;
        newfile.open("logins.txt", std::ios::in);
        if (newfile.is_open()) {

            std::string temp;
            while (getline(newfile, temp)) {
                if (login == temp) {
                    std::cout << "proper login" << std::endl;
                    newfile.close();
                }
                else {
                    std::cout << "login is not in the file, would you like to add it in the file? (Y/N) \n";
                    std::cin >> answer;
                    if (answer == "Y") {
                        ///PLIK WPISYEWANIE
                        insert.open("logins.txt", std::ios_base::app);
                        insert << this->login;
                        this->properlogin = false;
                        std::cout << "Login has been added to the file, you can try and login again!\n";
                        newfile.close();
                    }
                    else {
                        std::cout << "ok, have a nice day " << std::endl;
                        this->properlogin = false;
                        newfile.close();
                    }
                }
            
                
                
            }

        }
    }
    void LoginInFile() {

        std::string linelogin;
        std::vector < std::string> loginscontainer;
        std::ifstream loginfile;
        std::string answer;
        loginfile.open("logins.txt", std::ios::in);
        if (loginfile.is_open()) {

            std::string temp;
            while (getline(loginfile, temp)) {
                if (temp.empty()) {
                    break;
                }

                else {
                    loginscontainer.push_back(temp);
                }

            }

        }
        else {
            std::cout << "Error while opening the file\n";
            this->logininfile = false;
        }
        auto it = find(loginscontainer.begin(), loginscontainer.end(), this->login);

        if (it == loginscontainer.end()) {
            std::cout << "login not found in file! \n";
            this->logininfile = false;
            std::cout << "Would you like to add new login to the file? (Y/N)\n";
            std::cin >> answer;
            if (answer == "Y") {
                NewLoginIntoFile();
                this->logininfile = false;
                this->properlogin = false;
            }
            else {
                std::cout << "";
                this->logininfile = false;
                this->properlogin = false;
            }
        }
        else {
            std::cout << "login found in file\n";
            this->logininfile = true;
            this->properlogin = true;
        }
    }
    void PasswordInFile() 
    {
        if (this->properlogin == false)
        {
            std::cout << "\n";
        }
        else
        {
            std::string linepassword;
            std::vector < std::string> passwordcontainer;
            std::ifstream passwordfile;
            std::string answer;
            passwordfile.open("passwords.txt", std::ios::in);
            if (passwordfile.is_open()) 
            {

                std::string temp;
                while (getline(passwordfile, temp)) 
                {
                    if (temp.empty()) {
                        break;
                    }

                    else {
                        passwordcontainer.push_back(temp);
                    }

                }

            }
            else {
                std::cout << "Error while opening the file\n";
                this->passwordinfile = false;
            }
            auto it = find(passwordcontainer.begin(), passwordcontainer.end(), this->password);

            if (it == passwordcontainer.end()) {
                std::cout << "password not found in file! \n";
                this->passwordinfile = false;
                std::cout << "Would you like to add new password to the file? (Y/N)\n";
                std::cin >> answer;
                if (answer == "Y") {
                    NewPasswordIntoFile();
                    this->passwordinfile = false;
                    this->properpassword = false;
                }
                else {
                    std::cout << "";
                    this->passwordinfile = false;
                    this->properpassword = false;
                }
            }
            else {
                std::cout << "passoword found in file\n";
                this->passwordinfile = true;
                this->properpassword = true;
            }

        }
    }
        void NewLoginIntoFile() {

            std::ofstream savenewlogin("logins.txt");
            savenewlogin << this->login;
            savenewlogin.close();
        }

        void NewPasswordIntoFile() {

            std::ofstream savenewpassword("passwords.txt");
            savenewpassword << this->password;
            savenewpassword.close();
        }
    
};





int main()
{
    //std::cout << "Hello World!\n";

    User Mike;
    Mike.Logowanie();
    //User* user;
    //delete[] user;

  

}
