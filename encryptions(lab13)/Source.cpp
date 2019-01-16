//#include "stdafx.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
//#include <string>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

using namespace std;

int main()
{
	// работа с криптофункциями OpenSSL:
	// 1) создание объекта с настройками
	// 2) собственно, шифрование
	// 3) финализация
	// 4) и вывод зашифрованных данных

	// как правило, в литературе, структуры используются для хранения только данных
	// ни слова о методах и конструкторах/деструкторах
	struct name_of_my_struct // сродни классу
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};

	unsigned char *plaintext = (unsigned char *)"Some text";
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

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
	int len;
	EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len);//собственно, шифрование
	int cryptedtext_len = len;


	// 5. Финализация процесса шифрования
	// необходима, если последний блок заполнен данными не полностью
	EVP_DecryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;


	// 6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);

	// вывод зашифрованных данных
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;

	// РАСШИФРОВКА

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором

	// 3.
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;
	fstream t1, t2;
	t1.open("t1.txt", fstream::in | fstream::binary);
	t2.open("t2.txt", fstream::out | fstream::binary);
	char buffer1[256] = { 0 };
	char * buffer2[256] = { 0 };
	//t1.open("t1.txt",ios::in, ios::binary);
	//if (!t1.is_open()) { cout << "t1 not found" << endl; }
	//t2 open("t2.txt", ios::out, ios::binary  );
	//if (!t2.is_open()) cout << "t2 not found" << endl;
	len = 0;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	t1.read(buffer1, 256);
	while (t1.gcount() > 0)//пока в файле что-то есть
	{
		EVP_EncryptUpdate(ctx, // объект с настройками
			(unsigned char *)buffer2, // входной параметр: ссылка, куда помещать зашифрованные данные
			&len, // выходной параметр: длина полученного шифра
			(unsigned char *)buffer1, // входной параметр: что шифровать
			plaintext_len); // входной параметр : длина входных данных
		//fwrite(cryptedtext, 1, len, t2);
		t2.write((const char*)buffer2, len);
		t1.read(buffer1, 256);
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)buffer2, &len);
	t2.write((const char *)buffer2, len);// записали это в фаил
	t2.close();
	t1.close();
	memset(buffer1, 0, sizeof(char) * 256);
	memset(buffer2, 0, sizeof(char) * 256);
	//rashifrovka
	fstream t3, t4;
	t3.open("t2.txt", fstream::in | fstream::binary);
	t4.open("t3.txt", fstream::out | fstream::binary);
	ctx = EVP_CIPHER_CTX_new();

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

	t3.read(buffer1, 256);
	while (t3.gcount() > 0)//пока в файле что-то есть
	{
		EVP_DecryptUpdate(ctx, // объект с настройками
			(unsigned char *)buffer2, // входной параметр: ссылка, куда помещать зашифрованные данные
			&len, // выходной параметр: длина полученного шифра
			(unsigned char *)buffer1, // входной параметр: что шифровать
			plaintext_len); // входной параметр : длина входных данных
		//fwrite(cryptedtext, 1, len, t2);
		t4.write((const char*)buffer2, len);
		t3.read(buffer1, 256);
	}

	EVP_DecryptFinal_ex(ctx, (unsigned char *)buffer2, &len); //если в первый раз у нас была шлифовка пивком, то тут получается зачистка пивком? надо подумать
	t4.write((const char *)buffer2, len);

	t4.close();
	t3.close();

	system("pause");
	return 0;
}
