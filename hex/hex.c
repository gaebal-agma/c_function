#include<stdio.h>

//#define FILELEN 15

int ascii_to_hex(char c) //ASCII 값을 HEX로 변경해주는 코드, 값의 범위를 제한함. 
{
    int num = (int)c;
    if (num < 58 && num > 47)
    {
        return num - 48;
    }
    if (num < 103 && num > 96)
    {
        return num - 87;
    }
    return num;
}

int main()
{
    FILE * fp = fopen("./ARIA128(CBC)KAT.req", "r");
    unsigned char c1, c2;
    int i = 0;
    unsigned char sum, final_hex[15 / 2];
    for (i = 0; i <15 / 2; i++)
    {
        c1 = ascii_to_hex(fgetc(fp));
        c2 = ascii_to_hex(fgetc(fp));
        sum = c1 << 4 | c2;
        final_hex[i] = sum;
        printf("%02X ", sum);
    }
    printf("\n");
}