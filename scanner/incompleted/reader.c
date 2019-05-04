/* 
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdio.h>
#include "reader.h"

FILE *inputStream;
int lineNo, colNo;
int currentChar;

int readChar(void) {
  currentChar = getc(inputStream);
  colNo ++;
  if (currentChar == '\n') {
    lineNo ++;
    colNo = 0;
  }
  //char x=currentChar;
  //printf("%d %c \n",currentChar,x );
  return currentChar;
}
int openInputStream(char *fileName) { // mở file
  inputStream = fopen(fileName, "rt");
  if (inputStream == NULL)
    return IO_ERROR; 
  lineNo = 1; // khởi tạo ra cho dòng đấy là 1
  colNo = 0;  // khởi tạo ko.
  readChar();
  return IO_SUCCESS;
} //để xem thế này rồi có đọc được tất cả các chữ hay không.
void closeInputStream() {
  fclose(inputStream);
}

