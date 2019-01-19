
//#include "stdafx.h"
#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")
//
//extern "C" _declspec(dllimport) int RSA_public_encrypt(int flen, const unsigned char *from, const unsigned char *to, RSA *rsa, int padding);

// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	// работа с криптофункциями OpenSSL:
	// 1) создание объекта с настройками
	// 2) собственно, шифрование	
	// 3) финализация
	// 4) и вывод зашифрованных данных

	// как правило, в литературе, структуры используются для хранения только данных
	// ни слова о методах и конструкторах/деструкторах 
	char D[255];
	fstream fd;
	fstream fe;
	fstream fS;

	unsigned char *plaintext = /*(unsigned char *)D;*/
		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// исходный текст
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

									  //открыть файл в бинарном виде 

									  //f0.open("f0.txt", std::fstream::in | std::fstream::binary); // файл с исходными данными

									  // 1. Создаётся указатель на несуществующую структуру
									  // структура - тип данных в C++, близка к КЛАССУ, различия минимальны
	EVP_CIPHER_CTX *ctx; // structure

						 // 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

								// 3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv); // рандомайзер (случайный начальный вектор)

			 // 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate

	char str[256];
	int len = 0;
	int cryptedtext_len = len;
	ifstream input("input.txt", std::fstream::in, std::fstream::binary);//in-только чтение
	std::fstream output;
	output.open("out.txt", std::fstream::out | std::fstream::in | std::fstream::trunc | std::fstream::binary);//out-запись,
	//trunc-удалить содержимое файла, если он существует

	input.read(str, 256);// считывание из бинарного файла
	while (input.gcount() > 0)//цикл выполняется, пока в файле что-то есть

	{
		EVP_EncryptUpdate(ctx, // объект с настройками
			cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
			&len, // выходной параметр: длина полученного шифра
			(unsigned char *)str, input.gcount());
		// входной параметр: что шифровать
		// входной параметр : длина входных данных
		cryptedtext_len = len;
		output.write((char *)cryptedtext, len);//запись в файл шифрованного текста
		input.read(str, 256);
	}



	// 5. Финализация процесса шифрования
	// необходима, если последний блок заполнен данными не полностью
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	cryptedtext_len += len;
	output.write((char *)cryptedtext, len);
	input.close();

	// 6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);
	output.close();

	// вывод зашифрованных данных
	//for (int i = 0; i < cryptedtext_len; i++)
	//{
	//	cout << hex << cryptedtext[i];
	//	if ((i + 1) % 32 == 0) cout << endl;
	//	
	//}
	//fS << D << "привет";

	//cout << endl;


	// РАСШИФРОВКА

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

								// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором
	std::fstream deshef_input;
	deshef_input.open("out.txt", std::fstream::in | std::fstream::binary);
	std::fstream deshef_output;
	deshef_output.open("deasd_output.txt", std::fstream::out | std::fstream::in | std::fstream::trunc | std::fstream::binary);
	char str2[256];
	deshef_input.read(str2, 256);//считывание из бинарного файла
	while (deshef_input.gcount() > 0)
	{
		EVP_DecryptUpdate(ctx,
			decryptedtext,
			&len,
			(unsigned char *)str2,
			deshef_input.gcount());  // СОБСТВЕННО, ШИФРОВАНИЕ

		cryptedtext_len = len;
		deshef_output.write((char *)decryptedtext, len);
		deshef_input.read(str2, 256);
	}
	EVP_DecryptFinal_ex(ctx, decryptedtext, &len);

	EVP_CIPHER_CTX_free(ctx);
	deshef_output.write((char*)decryptedtext, len);
	deshef_output.close();
	deshef_input.close();
	

	// --- шифрование файла
	// производится точно так же, но порциями, в цикле
	// в цикле
	/*
	1) открытие файлов и настройка параметров OpenSSL
	2) считывание первого блока
	3) while(считанный_фрагмент > 0)
	{
	4) шифрование считанного
	5) запись зашифрованного массива в файл
	6) считывание следующего фрагмента
	}
	7) применение финализирующей фукнции
	8) запись финализирующего блока в файл
	9) закрытие файлов
	*/
	getchar();
	return 0;
}