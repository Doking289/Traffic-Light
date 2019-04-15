/* Программа "Traffic light" - представляет работу светофора.
В начале пользователю нужно зарегистрироваться как администратору. Придумтаь логин и пароль.
После, предлагется дефолтная установка частоты сигналов светофора. Пользователь может как согласиться, так и задать свою.
Дальше наблюдаем работу светофора. 
В программе есть специальные предустановленные "ошибки". Их может решить администратор. Нужно ввести пароль и согласиться на исправление ошибки.
Так же если пользователь забыл пароль или не знает его, то он может проигнорировать ошибку командой "exit", так же
если пользователь хочет выйти из программы, достаточно ввести команду "gg".
Для юзабильности в коде программы есть подсказки и проверки на ввод, чтобы пользователь не мог помешать работе программы

Удачного пользования :-)
*/

#include "pch.h" // Испольщованные библиотеки
#include "iostream"
#include "Windows.h"
#include "ctime"
#include "string"
#include "conio.h"
using namespace std; // За это сорри


// Глоюальные переменные
const int SLEEP_R = 0; // Дефолтное значение для КРАСНОГО
const int SLEEP_Y = 0; // Дефолтное значение для ЖЕЛТОГО			
const int SLEEP_G = 0; // Дефолтное значение для ЗЕЛЁНОГО
const int live_programm = 1000; // Жизненный цикл программы


// Прототипы функций

void SetLogin(string &set_login); // Регистрация login'a Admin'a
void SetPassword(string &set_pass); // Регистрация password'a Admin'a
void Admin(string &pass); // Ввод пароля Admin'a
void NoAdmin(); // Ответ на отсутсвие пароля


// Класс и его методы
class TrafficLight{
private: // Инкапсулюция
	int sleep_R, sleep_Y, sleep_G, random; 
	string pass, set_pass;
public:
	TrafficLight(); // Конструктор
	~TrafficLight(); // Деструктор
	// void Color - основной метод класса 'TrafficLight'
	void Color(string red, string yellow, string green, int &sleep_R, int &sleep_Y, int &sleep_G, int &radom1, string &pass1, int value, string &setPas, string &setLog);
	void sleeping(int &sleep_R, int &sleep_Y, int &sleep_G); // Установка таймера для сигналов светофора
	void Default_sleeping(int &sleep_R, int &sleep_Y, int &sleep_G); // Дефолтные значения для сигналов светофора
	void ErrorEdit(int &sleep_R, int &sleep_Y, int &sleep_G);// Подтверждение исправление ошибки
	void error_for_color(int &random1, string &pass1, int value1, string &setPass, string &setLog, int &sleep_R, int &sleep_Y, int &sleep_G);// Решение предустановленной ошибки
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	string red = " Red\n";
	string yellow = " Yellow\n";
	string green = " Green\n";
	string value, Value; string *Pvalue = &value;
	string Login; string *PLogin = &Login;

	int val2; int *Pval2 = &val2;
	int val1; int *Pval1 = &val1;
	int val3; int *Pval3 = &val3;
	int val4; int *Pval4 = &val4;
	int val5; int *Pval5 = &val5;

	cout << "\tRegistration Admin\n";
	SetLogin(*PLogin);
	SetPassword(*Pvalue);
	TrafficLight first;
	first.Default_sleeping(*Pval1, *Pval2, *Pval3);
	first.sleeping(*Pval1, *Pval2, *Pval3);
	first.Color(red, yellow, green,
				*Pval1, *Pval2, *Pval3,
				*Pval4, Value, *Pval5,
				*Pvalue, *PLogin);

	system("pause");
	return 0;
}

void TrafficLight::ErrorEdit(int &sleep_R, int &sleep_Y, int &sleep_G) {
	string errors_name, edit_value;
	/*int val1,val2, val3;
	int *Pval1 = &val1; int *Pval2 = &val2; int *Pval3 = &val3;*/
	for (int i = 0;; )
	{
		cout << " Need to fix\n"; cout << " Fix error?: "; getline(cin, errors_name);
		if (errors_name == "y"){
			cout << "-------\n";
			cout << " Done!\n";
			cout << "-------\n";
			for (int  j = 0;; )
			{
				cout << " Do you want to change timer for traffic light?: "; getline(cin, edit_value);
				if (edit_value == "y"){
					cout << "OK" << endl;
					sleeping(sleep_R, sleep_Y, sleep_G);
					break;
				}
				else if (edit_value == "n") {
					cout << "NOT OK" << endl;
				//	this->sleep_R = this->sleep_Y = this->sleep_G = SLEEP_G; ///////////////////////////////////////////////////////////////////////////////////////////////
					break;
				}
				else
					j++;

			}
			break;

		}
		else if (errors_name == "n") {
			cout << "-------\n";
			cout << " Error not fix\n";
			cout << "-------\n";
			break;
		}
		else
			i++;
	}
}

void TrafficLight:: Default_sleeping(int &sleep_R, int &sleep_Y, int &sleep_G) {
	sleep_R = SLEEP_R;
	sleep_Y = SLEEP_Y;
	sleep_G = SLEEP_G;
}
void SetLogin(string &set_login) {
	cout << " Login: "; getline(cin, set_login);
}

void SetPassword(string &set_pass) {
	cout << " Password: "; getline(cin, set_pass); cout << " Registration completed!\n";
	system("cls");
}



void TrafficLight:: sleeping(int &sleep_R, int &sleep_Y, int &sleep_G) {
	//this->sleep_R = sleep_R; this->sleep_Y = sleep_Y; this->sleep_G = sleep_G;
	string answer1;
	for (int i = 0; i < live_programm; ){

		cout << " Setting default frequency?(y = yes; n = no): "; getline(cin, answer1);	

		if (answer1 == "y"){
			cout << " OK.";
			cout << " Press 'Enter'\n";
			Default_sleeping(sleep_R, sleep_Y, sleep_G);
			break;
		}
		if (answer1 == "n") {
			cout << " For Red: "; cin >> sleep_R;
			cout << " For Yellow: "; cin >> sleep_Y;
			cout << " For Green: "; cin >> sleep_G;
			cout << endl;
			cin.clear(); cin.ignore();
			break;
		}
		else
			i++;
	}

}

void Admin(string &pass) {
	cout << " Enter password or 'exit' without error correction or 'gg' for exit in programm: "; getline(cin, pass);
}

void NoAdmin() {
	cout << " Your not admin\n";
}

void TrafficLight::error_for_color(int &random1, string &pass1, int value1, string &setPass, string &setLog, int &sleep_R, int &sleep_Y, int &sleep_G) {
	value1 = 1;
	random1 = rand() % 10; // Рандомный подбор предустановленной ошибки 
	if (random1 == value1) {
		cout << "------";
		cout << " \nError!\n";
		cout << "------\n";
		for (int j = 0;; ) {
			Admin(pass1); 
			if (pass1 == setPass) {
				cout << " Hello " << setLog << endl;
				ErrorEdit(sleep_R, sleep_Y, sleep_G);
				break;
			}
			if (pass1 == "exit") {
				cout << " Error not fix\n";
				break;
			}
			if (pass1 == "gg"){
				cout << " Thanks for the work\n"; system("pause");
				exit(1);
			}
			else {
				NoAdmin();
				j++;
			}
		}
	}
}

void TrafficLight::Color(string red, string yellow, string green, int &sleep_R, int &sleep_Y, int &sleep_G, int &random1, string &pass1,  int value, string &setPas, string &setLog) {

	cin.clear(); cin.ignore();
	value = 1;
	for (int i = 0; i < live_programm; i++){
		cout << red;
		Sleep(sleep_R);
		error_for_color(random1, pass1, value, setPas, setLog, sleep_R, sleep_Y, sleep_G);
		cout << yellow;
		Sleep(sleep_Y);
		error_for_color(random1, pass1, value, setPas, setLog, sleep_R, sleep_Y, sleep_G);
		cout << green;
		Sleep(sleep_G);
		cout << endl;
		error_for_color(random1, pass1, value, setPas, setLog, sleep_R, sleep_Y, sleep_G);
	}
}

TrafficLight::TrafficLight(){
	cout << "\tTrafficLightfic light\n\n";
}
TrafficLight::~TrafficLight(){
	cout << " Close\n";
}