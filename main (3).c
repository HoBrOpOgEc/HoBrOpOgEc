#include <stdio.h>
#include <stdint.h>

#define BUFF_SIZE 512

/* принцип
Сообщение считывается
Делится на блоки по 8 байт (64 бит)
рассматривается 1 блок, в котором он сам делится пополам (32 бит)


*/

/* new for me

uint8_t - тип данных с точной шириной (8-байтовый без знака )

size_t - беззнаковый целый тип, предназначенный для представления размера любого объекта в памяти (включая массивы) в конкретной реализации

операнд-1 ? операнд-2 : операнд-3 - ТЕРНАРНАЯ ОПЕРАЦИЯ
Если операнд-1 не равен 0, то вычисляется операнд-2 и его значение является результатом операции. Если операнд-1 равен 0, то вычисляется операнд-3 и его значение является результатом операции.

*/

//FEISTEL NETWORK
{
/* Функция, выполняющая преобразование подблока с учётом значения ключа (по ключу). 
Реализация зависит от выбранного алгоритма блочного шифрования. */
int f (
        int subblock,  /* преобразуемый подблок */
        int key        /* ключ */
);  /* возвращаемое значение - преобразованный блок */

/* Функция, выполняющая шифрование открытого текста */
void crypt (
        int * left,   /* левый входной подблок */
        int * right,  /* правый входной подблок */
        int rounds,   /* количество раундов */
        int * key     /* массив ключей (по ключу на раунд) */
) {
    int i, temp;
    for ( i = 0; i < rounds; i++ )
    {
        temp = *right ^ f( *left, key[i] );
        *right = *left;
        *left = temp;
    }
}

/* Функция, выполняющая расшифрование текста */
void decrypt (
        int * left,   /* левый зашифрованный подблок */
        int * right,  /* правый зашифрованный подблок */
        int rounds,   /* количество раундов */
        int * key     /* массив ключей (по ключу на раунд) */
) {
    int i, temp;
    for ( i = rounds - 1; i >= 0; i-- )
    {
        temp = *left ^ f( *right, key[i] );
        *left = *right;
        *right = temp;
    }
}
}


// 1 | 4 -> 0xC ТАБЛИЦА ЗАМЕН
static const uint8_t Sbox[8][16] = { 
	{0xF, 0xC, 0x2, 0xA, 0x6, 0x4, 0x5, 0x0, 0x7, 0x9, 0xE, 0xD, 0x1, 0xB, 0x8, 0x3}, 
	{0xB, 0x6, 0x3, 0x4, 0xC, 0xF, 0xE, 0x2, 0x7, 0xD, 0x8, 0x0, 0x5, 0xA, 0x9, 0x1},
	{0x1, 0xC, 0xB, 0x0, 0xF, 0xE, 0x6, 0x5, 0xA, 0xD, 0x4, 0x8, 0x9, 0x3, 0x7, 0x2},
	{0x1, 0x5, 0xE, 0xC, 0xA, 0x7, 0x0, 0xD, 0x6, 0x2, 0xB, 0x4, 0x9, 0x3, 0xF, 0x8},
	{0x0, 0xC, 0x8, 0x9, 0xD, 0x2, 0xA, 0xB, 0x7, 0x3, 0x6, 0x5, 0x4, 0xE, 0xF, 0x1},
	{0x8, 0x0, 0xF, 0x3, 0x2, 0x5, 0xE, 0xB, 0x1, 0xA, 0x4, 0x7, 0xC, 0x9, 0xD, 0x6},
	{0x3, 0x0, 0x6, 0xF, 0x1, 0xE, 0x9, 0x2, 0xD, 0x8, 0xC, 0x4, 0xB, 0xA, 0x5, 0x7},
	{0x1, 0xA, 0x6, 0x8, 0xF, 0xB, 0x0, 0x4, 0xC, 0x3, 0x5, 0x9, 0x7, 0xD, 0x2, 0xE},
};

main()
{
    uint8_t key256b[32] = "this_is_a_pasw_for_GOST_28147_89"; // ключ для шифра "что угодно, главное 32 символа"
    uint8_t encrypted[BUFF_SIZE], decrypted[BUFF_SIZE];   
    
    //берем сообщение
	uint8_t buffer[BUFF_SIZE], ch;
	size_t position;
	while ((ch = getchar()) != '\n' && position < BUFF_SIZE - 1)
		buffer[position++] = ch;
	buffer[position] = '\0'; // для того, чтобы обозначить конец сообщения
	
	
	
}




//(куда_попадает за/расшифрованное сообщение, ОПЦИЯ, ключ256, сообщение, длина сообщения )
size_t GOST_MAGMA (uint8_t encripted, uint8_t mode, uint8_t *key256b, uint8_t *buffer, uint8_t lenght) 
{
    lenght=(lenght%8==0) ? lenght : lenhgt+(8-(lenght%8)); //нашли длину сообщения
    uint8_t R,L,keys32b[8];
    split_from_256_to_32(key256b,keys32b); //расфигачиваем ключ на блоки по 32 бита
    
    for (size_t i=o;i<lenght;i+=8)
        {
            split_from_64_to_32(join_from_8_to_64(from + i), &R,&L);
        }
        
    feistel(        )
}






void split_from_256_to_32(uint8_t *key256b, uint32_t *keys32b)
{
    uint8_t *p8 = key256b;
        for (uint32_t *p32=keys32b; p32<keys32b; ++p32)
        {
            for (int i=0;i<4;++i);
            {
                *p32=(*p32<<8)|*(p8+i);
            }
            p8+=4;
        }
}


//функция разбиения 
void split_from_64_to_32(uint8_t block64, uint8_t *block32_1, uint8_t *block32_2)
{
    block32_1=(uint32_t)(block64b);
    
    block32_2=(uint32_t)(block64b>>32);
}


//функция, которая будет собирать шифр из 8 бит в 64
void join_from_8_to_64(uint8_t *blocks8b)
{
    for (uint8_t *p=blocks8b; p<blocks8b+8;++P)
    {
        block64b=(block64b<<8) | *p;
    }
    return block64b
}


//получили блоки, можно при помощи сети фейстеля делать преобразования (ОПЦИЯ, Блок Левый, Блок Правый, Ключи 32бит)
void FEISTEL (uint8_t mode, uint32_t *block32_1, uint32_t *block32_2, uint32_t *keys32b)
{
    switch(mode)
        {
            case 'E': case'e':
            {
                for (uint8_t round=0; round<24l; ++round)
                {
            }
        }
}


//раунд (цикл)  (Блок Левый, Блок Правый, Ключ 32 бита, раунд)
void round_of_FEISTEL (uint32_t *block32_1, uint32_t *block32_2, uint32_t keys32b, uint8_t round)
{
    uint32_t result, tmp;
    
    	// result=(L + Ki) mod 2^32
    result=(*block32_1 + keys32b[round % 8]) % UINT32_MAX;
    
    
    // RES = RES -> Sbox
	result=substitution_table(result, round % 8);
}
