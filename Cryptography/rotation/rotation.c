#include <stdio.h>
#include <string.h>

int main(){
  char encrypted_text[37];
  strcpy(encrypted_text, "xqkwKBN{z0bib1wv_l3kzgxb3l_7l140864}");
  
  for(int i = 0;i < 37; i++){
    if(encrypted_text[i] >= 65 && encrypted_text[i] <= 90){
      encrypted_text[i] = ((encrypted_text[i] - 65 - 8 + 26) % 26) + 65;
    }
    if(encrypted_text[i] >= 97 && encrypted_text[i] <= 122){
      encrypted_text[i] = ((encrypted_text[i] - 97 - 8 + 26) % 26) + 97;
    }
  }
  printf("%s\n",encrypted_text);
}
