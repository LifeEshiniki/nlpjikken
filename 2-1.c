/*
課題２－１
アルゴリズム
文字種を分ける（範囲指定、場合分け）
• ASCII 文字（数字、アルファベット、記号を含む 1byte 文字）
• 平仮名 
• 片仮名 
• 横棒（‘ー’） 
• 数字 
• 2byte コードとしてのアルファベット 
• 漢字 
• 句読点（‘。’, ‘、’, ‘！’, ‘？’ の４種）
• その他
↓
１文字ごとに文字種を調べる
↓
もし前の文字と異なれば改行を入れる

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCIITYPE_S 0x00
#define ASCIITYPE_E 0x7f
#define HIRAGANA_S 0xa4a1
#define HIRAGANA_E 0xa4f3
#define KATAKANA_S 0xa5a1
#define KATAKANA_E 0xa5f6
#define NUMBER_S 0x30
#define NUMBER_E 0x39
#define TWOBYTECODE_S 0xa3b0
#define TWOBYTECODE_E 0xa3fa
#define KANJI_S 0xb0a1
#define KANJI_E 0xf4fe 
#define KUTOUTEN_S 0xa1a1
#define KUTOUTEN_E 0xa1aa
#define ASCIITYPE 1
#define HIRAGANA 2
#define KATAKANA 3
#define NUMBER 4
#define TWOBYTECODE 5
#define KANJI 6
#define KUTOUTEN 7
#define DASH 0xa1bc
#define other 0


int check_character(char *character,int n){
    /*文字列を受け取り、*/
    moji = atoi(character);
    if (moji >= HIRAGANA_S && moji <= HIRAGANA_E){
        return HIRAGANA;
    }
    else if(moji >= KATAKANA_S && moji <= KATAKANA_E){
        return KATAKANA;
    } 
    else if(moji >= ASCIITYPE_S && moji <= ASCIITYPE_E){
        return ASCIITYPE;
    } 
    else if(moji >= NUMBER_S && moji <= NUMBER_E){
        return NUMBER;
    } 
    else if(moji >= TWOBYTECODE_S && moji <= TWOBYTECODE_E){
        return TWOBYTECODE;
    } 
    else if(moji >= KANJI_S && moji <= KANJI_E){
        return KANJI;
    } 
    else if(moji >= KUTOUTEN_S && moji <= KUTOUTEN_E){
        return KUTOUTEN;
    } 
    else{
        return OTHER;
    }

}


int main (void){
    int c,n;
    unsigned char string[];
    char *euc_ch;
    int check[2];
    
    while((c = getchar())!= EOF){ /*一文字ずつ読み込む、文章が終わるまで*/
        if(c >=128){
            euc_ch = c;
            if((c = getchar())!= EOF){
                euc_ch + 1 = c; /*EUC2byte文字*/
                euc_ch + 2 = '\0'; 
            }else{
                printf("input text is not encoded EUC code.\n");
                
            }
        }
        else if(c == '\n'){
            continue;
        }
        else{
            euc_ch = c;
            euc_ch + 1 = '\0';
        }

        /*読み込んだ文字種のチェック*/
        check[1] = check_character(euc_ch);


        /*隣り合う文字種が同じかどうか*/
        if(check[0] == check[1]){
            printf("%s",euc_ch);
        }
        else{
            printf("\n%s",euc_ch);
            check[0] = check[1];
        }
    return 0;
}