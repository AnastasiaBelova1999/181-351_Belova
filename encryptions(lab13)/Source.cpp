// Шифрование.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <openssl/conf.h> //функции,
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <fstream>

using namespace std;


int main()
{
	//как правило, в литературе, структуры используются для хранения только данных
	//ни слова не говорится о методах и конструкторах/деструкторах
	struct name_of_my_struct
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

	unsigned char *plaintext = (unsigned char *)"Some text Some text Some text Some text"; //исходный текст
	int plaintext_len = strlen((char *)plaintext); //длина текста
	unsigned char *key = (unsigned char *)"0123456789"; //пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; //инициализирующий вектор
	unsigned char cryptedtext[256]; //зашифрованный результат
	unsigned char decryptedtext[256]; //расшифрованный результат

	//1. Создается указатель на несуществующую структуру
	EVP_CIPHER_CTX *ctx; //structure
	//2. Для указателя создается пустая структура настроек(метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new();//создание структуры с настройками метода
	//3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);//инициализация методом AES, ключом и вектором
	//4. Сам процесс шифрования - функция EVP_EncryptUpdate
	int len;
	EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len);//собственно, шифрование
	int cryptedtext_len = len;

	//5.Финализация процесса шифрования
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	//6.Удаление структуры
	EVP_CIPHER_CTX_free(ctx); \
		for (int i = 0; i < cryptedtext_len; i++)
		{
			cout << hex << cryptedtext[i];
			if ((i + 1) % 32 == 0) cout << endl;
		}
	cout << endl;
	//BIO_dump_fp(stdout, (char*)cryptedtext, cryptedtext_len-1);


	//1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	//2.

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);//инициализация методом AES, ключом и вектором

	//3. 
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);//собственно, шифрование

	//4.
	int decrypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	//5.
	decrypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[decrypted_len] = '\0';
	cout << decryptedtext << endl;

	//AES_cfb128_encrypt()


	//шифрование файла производится точно так же, но порциями, в цикле
	fstream f0, f_encrypted;
	f0.open("f0.txt", std::fstream::in);
	f_encrypted.open("f_encrypted.txt", std::fstream::out | std::fstream::trunc);
	unsigned int number_of_bytes = 0;
	unsigned int filesize = 0;
	char buffer[AES_BLOCK_SIZE] = { 0 };
	char * out_buf[AES_BLOCK_SIZE] = { 0 };
	AES_KEY aes_key;
	AES_set_encrypt_key(key, 128, &aes_key);
	while (true) //бесконечный цикл считывания порций файла, шифрования и записи в другой файл
	{
		//считывание
		f0.read(buffer, AES_BLOCK_SIZE);
		number_of_bytes += AES_BLOCK_SIZE;

		//шифрование
		AES_cfb128_encrypt((unsigned char *)buffer,
			(unsigned char *)out_buf,
			AES_BLOCK_SIZE,
			&aes_key, iv, 0,
			AES_ENCRYPT);
		f_encrypted.close();
		f0.close();
		//запись
		if (number_of_bytes == filesize) break;

		// --- шифрование файла
		// производится точно так же, но порциями, в цикле
		// в цикле
		/*
		//1)открытие файлов и настройка параметров OpenSSL
		//в цикле
		 while (считанный_фрагмент > 0)
		 {
		 //шифрование считанного
		 //запись зашифрованного массива в файл
		 //считывание следующего фрагмента
		 }
		 //применение финализирующей функции
		 //запись финализирующего блока в файл
		 //закрытие файлов
		*/
		fstream f0, f_encrypted, f_decrypted;
		f0.open("f0.txt", std::fstream::in); // файл  с исходными данными
		//файл для зашифрованных данных
		f_encrypted.open("f_encrypted.txt",
			std::fstream::out | std::fstream::trunc);

		char buffer[256] = { 0 };
		char out_buf[256] = { 0 };

		ctx = EVP_CIPHER_CTX_new();
		EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
		len = 0;
		f0.read(buffer, 256);
		while (f0.gcount() > 0) //цикл, пока из фАЙЛА ЧТО-ТО СЧИТЫВАЕТСЯ(пока размер считанной порции > 0)
		{
			//шифрование порции
			EVP_EncryptUpdate(ctx, //объект с настройкамии
				(unsigned char *)out_buf, //входной параметр:ссылка, куда помещать зашифрованные данные
				&len, //выходной параметр: длина полученного шифра
				(unsigned char *)buffer,//входной параметр: что шифровать
				f0.gcount()); //входной параметр: длина входных данных

	//вывод зашифрованной порции в файл
			f_encrypted.write(out_buf, len);

			//считывание следующей порции
			f0.read(buffer, 256);
		}
		EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
		f_encrypted.write(out_buf, len);
		f_encrypted.close();
		f0.close();

		memset(buffer, 0, sizeof(char) * 256);
		memset(out_buf, 0, sizeof(char) * 256);

		f_encrypted.open("f_enctypted.txt",
			std::fstream::in | std::fstream::binary);
		f_decrypted.open("f_decrypted.txt",
			std::fstream::in | std::fstream::out | std::fstream::trunc | std::fstream::binary);
		f_encrypted.read(buffer, 256);

		ctx = EVP_CIPHER_CTX_new();

		EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);


		while (f_encrypted.gcount() > 0)
		{
			// расшифровка 
			EVP_DecryptUpdate(ctx,
				(unsigned char *)out_buf,
				&len,
				(unsigned char *)buffer,
				f_encrypted.gcount());

			// запись расшифровки в файл 
			f_decrypted.write(out_buf, len);

			// чтение следующей порции 
			f_encrypted.read(buffer, 256);
		}

		EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
		f_decrypted.write(out_buf, len);

		f_decrypted.close();
		f_encrypted.close();

		system("pause");
		return 0;
	}
}

