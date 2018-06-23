
#include "stdafx.h"
#include "Converter.h"
#include <iostream>
#include <fstream>
//#using <mscorlib.dll>

using namespace std;

struct Conv_Tab1
{
	char vSrg;
	char vKump[8];
}Srg[237] = { 	
				  '�' , { 'S','u','d','h','e','e','r',   -1 } , // 1 
 'J' , { 'B' ,   -1 } , // 2 
 '�' , { 'C' ,   -1 } , // 3 

 '�' , { 'D' ,   -1 } , // 4 
 '�' , { 'C' ,   -1 } , // 5 
 '�' , { 'E' ,   -1 } , // 6 

 '(' , { 'E' ,   -1 } , // 7 
 '�' , { 'F' ,   -1 } , // 8 
 ')' , { 'F' ,   -1 } , // 9 

 '�' , { 'G' ,   -1 } , // 10 
 '+' , { 'G' ,   -1 } , // 11 
 '�' , { 'H' ,   -1 } , // 12 

 '!' , { 'H' ,   -1 } , // 13 
 '�' , { 'I' ,   -1 } , // 14 
 '_' , { 'I' ,   -1 } , // 15 

 '�' , { 'J' ,   -1 } , // 16 
 '"' , { 'J' ,   -1 } , // 17 
 '�' , { 'K' ,   -1 } , // 18 

 '#' , { 'K' ,   -1 } , // 19 
 '�' , { 'L' ,   -1 } , // 20 
 '$' , { 'L' ,   -1 } , // 21 

 '�' , { 'M' ,   -1 } , // 22 
 '%' , { 'M' ,   -1 } , // 23 
 '�' , { 'N' ,   -1 } , // 24 

 '&' , { 'N' ,   -1 } , // 25 
 '�' , { 'O' ,   -1 } , // 26 
 '\'' , { 'O' ,   -1 } , // 27 

 '`' , { 'P' ,   -1 } , // 28 
 '�' , { 'P' ,  '�' ,   -1 } , // 29 
 ';' , { 'P' ,  '�' ,   -1 } , // 30 

 '!' , { 'H' ,   -1 } , // 1 
 '"' , { 'J' ,   -1 } , // 2 
 '#' , { 'L' ,   -1 } , // 3 

 '$' , { 'L' ,   -1 } , // 4 
 '%' , { 'M' ,   -1 } , // 5 
 '&' , { 'N' ,   -1 } , // 6 

 '\'' , { 'O' ,   -1 } , // 7 
 '(' , { 'E' ,   -1 } , // 8 
 ')' , { 'F' ,   -1 } , // 9 

 '+' , { 'G' ,   -1 } , // 10 
 '/' , { '�' ,   -1 } , // 11 
 '0' , { '0' ,   -1 } , // 12 

 '1' , { '1' ,   -1 } , // 13 
 '2' , { '2' ,   -1 } , // 14 
 '3' , { '3' ,   -1 } , // 15 

 '4' , { '4' ,   -1 } , // 16 
 '5' , { '5' ,   -1 } , // 17 
 '6' , { '6' ,   -1 } , // 18 

 '6' , { '7' ,   -1 } , // 19 
 '8' , { '8' ,   -1 } , // 20 
 '9' , { '9' ,   -1 } , // 21 

 ':' , { '�' ,   -1 } , // 22 
 ';' , { 'P' ,  '�' ,   -1 } , // 23 
 '<' , { 'Q' ,   -1 } , // 24 

 '>' , { 'U' ,  '�' ,   -1 } , // 25 
 '?' , { 'V' ,   -1 } , // 26 
 '@' , { '�' ,   -1 } , // 27 

 'A' , { '�' ,   -1 } , // 28 
 'C' , { '�' ,   -1 } , // 29 
 'D' , { '�' ,   -1 } , // 30 

 'E' , { '�' ,   -1 } , // 31 
 'F' , { '�' ,   -1 } , // 32 
 'G' , { '�' ,   -1 } , // 33 

 'H' , { '�' ,   -1 } , // 34 
 'I' , { 'A' ,   -1 } , // 35 
 'J' , { 'B' ,   -1 } , // 36 

 'K' , { 'i' ,   -1 } , // 37 
 'L' , { 'h' ,   -1 } , // 38 
 'M' , { '�' ,   -1 } , // 39 

 'N' , { '�' ,   -1 } , // 40 
 'O' , { '�' ,   -1 } , // 41 
 'P' , { '�' ,   -1 } , // 42 

 'Q' , { '�' ,   -1 } , // 43 
 'R' , { '�' ,   -1 } , // 44 
 'S' , { '�' ,   -1 } , // 45 

 'T' , { '�' ,   -1 } , // 46 
 'V' , { '�' ,   -1 } , // 47 
 'W' , { 'A' ,  'i' ,  '�' ,  '�' ,   -1 } , // 48 

 'Y' , { '�' ,   -1 } , // 49 
 'Z' , { '�' ,   -1 } , // 50 
 '[' , { '�' ,  '�' ,   -1 } , // 51 

 '\\' , { '�' ,  '�' ,   -1 } , // 52 
 '^' , { '�' ,   -1 } , // 53 
 '_' , { 'I' ,  '�' ,   -1 } , // 54 

 '`' , { 'P' ,   -1 } , // 55 
 'a' , { 'U' ,   -1 } , // 56 
 'b' , { 'F' ,   -1 } , // 57 

 'c' , { 'o' ,   -1 } , // 58 
 'd' , { 'q' ,   -1 } , // 59 
 'e' , { 'u' ,   -1 } , // 60 

 'f' , { 'v' ,   -1 } , // 61 
 'g' , { 'x' ,   -1 } , // 62 
 'h' , { 'z' ,   -1 } , // 63 

 'i' , { '�' ,   -1 } , // 64 
 'j' , { '�' ,   -1 } , // 65 
 'k' , { 'g' ,   -1 } , // 66 

 'l' , { '�' ,   -1 } , // 67 
 'm' , { '�' ,   -1 } , // 68 
 'n' , { '�' ,   -1 } , // 69 

 'o' , { '�' ,   -1 } , // 70 
 'p' , { '�' ,   -1 } , // 71 
 '.' , { 'R' ,   -1 } , // 72 

 '.' , { 'S' ,   -1 } , // 73 
 '�' , { '�' ,   -1 } , // 74 
 'Z' , { 'U' ,  '�' ,   -1 } , // 75 

 'a' , { 'V' ,   -1 } , // 76 
 ':' , { '�' ,   -1 } , // 77 
 'S' , { 'W' ,  '�' ,   -1 } , // 78 

 '�' , { 'X' ,   -1 } , // 79 
 '�' , { '�' ,   -1 } , // 80 
 'x' , { 'Z' ,  '�' ,   -1 } , // 81 

 '�' , { 'a' ,   -1 } , // 82 
 '�' , { '�' ,   -1 } , // 83 
 '�' , { 'd' ,   -1 } , // 84 

 '�' , { 'f' ,   -1 } , // 85 
 '�' , { '�' ,   -1 } , // 86 
 '�' , { 'l' ,   -1 } , // 87 

 '�' , { 'n' ,   -1 } , // 88 
 '�' , { '�' ,   -1 } , // 89 
 '�' , { 'o' ,  '�' ,   -1 } , // 90 

 '�' , { 'p' ,   -1 } , // 91 
 '�' , { '�' ,   -1 } , // 92 
 '�' , { '�' ,  '�' ,   -1 } , // 93 

 '�' , { 'q' ,  '�' ,   -1 } , // 1 
 '�' , { 'r' ,   -1 } , // 2 
 '�' , { '�' ,   -1 } , // 3 

 '�' , { 't' ,   -1 } , // 4 
 '�' , { 't' ,  '�' ,   -1 } , // 5 
 '�' , { 'v' ,  '�' ,   -1 } , // 6 

 '�' , { 'w' ,   -1 } , // 7 
 '�' , { '�' ,   -1 } , // 8 
 '�' , { 'x' ,  '�' ,   -1 } , // 9 

 '�' , { 'y' ,   -1 } , // 10 
 '�' , { '�' ,   -1 } , // 11 
 '.' , { '�' ,   -1 } , // 12 

 '�' , { '�' ,  '�' ,   -1 } , // 13 
 '�' , { '�' ,   -1 } , // 14 
 '�' , { '�' ,   -1 } , // 15 

 '.' , { '�' ,   -1 } , // 16 
 '�' , { '�' ,   -1 } , // 17 
 '�' , { '�' ,   -1 } , // 18 

 '�' , { '�' ,   -1 } , // 19 
 '�' , { '�' ,   -1 } , // 20 
 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 21 

 '�' , { '�' ,  '�' ,   -1 } , // 22 
 '�' , { 'A' ,  'i' ,  '�' ,  '�' ,   -1 } , // 23 
 '�' , { '�' ,  '�' ,   -1 } , // 24 

 '�' , { 'g' ,  '�' ,   -1 } , // 25 
 '�' , { 'j' ,   -1 } , // 26 
 '�' , { '�' ,   -1 } , // 27 

 '�' , { '�' ,   -1 } , // 28 
 '�' , { '�' ,   -1 } , // 29 
 '�' , { '�' ,  '�' ,   -1 } , // 30 

 '�' , { '�' ,   -1 } , // 31 
 '�' , { '�' ,  '�' ,   -1 } , // 32 
 '�' , { '�' ,   -1 } , // 33 

 '�' , { '�' ,   -1 } , // 34 
 '�' , { '�' ,  '�' ,   -1 } , // 35 
 '�' , { '�' ,   -1 } , // 36 

 '�' , { '�' ,   -1 } , // 37 
 '�' , { '�' ,  '�' ,   -1 } , // 38 
 '�' , { '�' ,   -1 } , // 39 

 '�' , { '�' ,   -1 } , // 40 
 '�' , { '.' ,  '�' ,   -1 } , // 41 
 '�' , { '�' ,   -1 } , // 42 

 '�' , { '�' ,   -1 } , // 43 
 '�' , { '�' ,  '�' ,   -1 } , // 44 
 '�' , { '�' ,   -1 } , // 45 

 '�' , { 'd' ,  '�' ,   -1 } , // 46 
 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 47 
 '�' , { '�' ,   -1 } , // 48 

 '�' , { 'b' ,  '�' ,   -1 } , // 49 
 ']' , { '�' ,   -1 } , // 50 
 'q' , { '�' ,   -1 } , // 51 

 'r' , { 'b' ,  's' ,  'q' ,  's' ,   -1 } , // 52 
 't' , { 'z' ,  's' ,   -1 } , // 53 
 'u' , { '�' ,  's' ,   -1 } , // 54 

 'v' , { '�' ,  's' ,   -1 } , // 55 
 'w' , { 'P' ,  '�' ,   -1 } , // 56 
 'y' , { '�' ,   -1 } , // 57 

 'z' , { 'R' ,   -1 } , // 58 
 '{' , { '�' ,   -1 } , // 59 
 '|' , { 'T' ,   -1 } , // 60 

 '}' , { '�' ,   -1 } , // 61 
 '~' , { 'a' ,   -1 } , // 62 
 '�' , { 'C' ,   -1 } , // 63 

 '�' , { 'D' ,   -1 } , // 64 
 '.' , { 'E' ,   -1 } , // 65 
 '�' , { 'F' ,   -1 } , // 66 

 '.' , { 'G' ,   -1 } , // 67 
 '&' , { 'H' ,   -1 } , // 68 
 ' ' , { 'J' ,   -1 } , // 69 

 '!' , { 'L' ,   -1 } , // 70 
 '�' , { 'L' ,   -1 } , // 71 
 '0' , { 'M' ,   -1 } , // 72 

 '`' , { 'N' ,   -1 } , // 73 
 '9' , { 'O' ,   -1 } , // 74 
 'R' , { 'I' ,  '�' ,   -1 } , // 75 

 '�' , { 'I' ,  '�' ,   -1 } , // 76 
 '�' , { 'W' ,   -1 } , // 77 
 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 78 

 '.' , { 'A' ,  'i' ,  '�' ,  '�' ,   -1 } , // 79 
 '.' , { '�' ,   -1 } , // 80 
 '.' , { 'P' ,  '�' ,   -1 } , // 81 

 '.' , { 'Q' ,   -1 } , // 82 
 '"' , { '�' ,   -1 } , // 83 
 '�' , { 'c' ,   -1 } , // 84 

 '�' , { '�' ,   -1 } , // 85 
 '�' , { 'q' ,  's' ,  '�' ,   -1 } , // 86 
 '�' , { 'r' ,  '�' ,   -1 } , // 87 

 '�' , { '�' ,   -1 } , // 88 
 '�' , { 'z' ,  's' ,  '�' ,   -1 } , // 89 
 '�' , { '�' ,  '�' ,   -1 } , // 90 

 '�' , { '�' ,   -1 } , // 91 
 '�' , { '�' ,  's' ,  '�' ,   -1 } , // 92 
 '�' , { '�' ,  '�' ,   -1 } , // 93 

 '�' , { '�' ,   -1 } , // 94 
 '�' , { '�' ,  's' ,  '�' ,   -1 } , // 95 
 '�' , { '�' ,  '�' ,   -1 } , // 96 

 '�' , { 'g' ,  '�' ,  'h' ,  '�' ,   -1 } , // 97 
 '�' , { 'j' ,  'h' ,  '�' ,   -1 } , // 98 
 '�' , { 'P' ,  '�' ,  '�' ,   -1 } , // 99 

 '�' , { 'Q' ,  '�' ,   -1 } , // 100 
 '�' , { 'Y' ,   -1 } , // 101 
 '�' , { '�' ,   -1 } , // 102 

 '�' , { '�' ,   -1 } , // 103 
 '�' , { 'W' ,  '�' ,   -1 } , // 104 
 '�' , { '�' ,   -1 } , // 105 

 '�' , { '�' ,  '�' ,   -1 } , // 106 
 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 107 
 '�' , { 'Z' ,  '�' ,   -1 } , // 108 

 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 109 
 '�' , { 'm' ,   -1 } , // 110 
 '�' , { '�' ,  's' ,  '�' ,  '�' ,   -1 } , // 111 

 '�' , { '�' ,  's' ,  '�' ,  '�' ,   -1 } , // 112 
 '�' , { 'C' ,   -1 } , // 113 
 '�' , { 'k' ,   -1 } , // 114 


};

struct Conv_Tab2
{
	char vSrg;
	char vKump[8];
}Sree[170] = {
				 'A' , { 'm' ,   -1 } , // 1 
				 'B' , { 'f' ,   -1 } , // 2 
				 'C' , { '^' ,   -1 } , // 3 

				 'D' , { '�' ,   -1 } , // 4 
				 'E' , { '�' ,   -1 } , // 5 
				 'F' , { '�' ,   -1 } , // 6 

				 'G' , { 'V' ,   -1 } , // 7 
				 'H' , { 'Y' ,   -1 } , // 8 
				 'I' , { '�' ,  '�' ,  '�' ,   -1 } , // 9 

				 'J' , { 'n' ,   -1 } , // 10 
				 'K' , { '�' ,   -1 } , // 11 
				 'L' , { '�' ,   -1 } , // 12 

				 'M' , { 'u' ,   -1 } , // 13 
				 'N' , { '�' ,   -1 } , // 14 
				 'O' , { '�' ,   -1 } , // 15 

				 'P' , { '�' ,   -1 } , // 16 
				 'Q' , { 'q' ,   -1 } , // 17 
				 'R' , { '_' ,   -1 } , // 18 

				 'S' , { 's' ,   -1 } , // 19 
				 'T' , { 'o' ,   -1 } , // 20 
				 'U' , { '�' ,   -1 } , // 21 

				 'V' , { '�' ,   -1 } , // 22 
				 'W' , { 'K' ,   -1 } , // 23 
				 'W' , { '�' ,  'J' ,   -1 } , // 24 

				 'X' , { 'g' ,   -1 } , // 25 
				 'Y' , { '�' ,   -1 } , // 26 
				 'Z' , { '�' ,   -1 } , // 27 

				 'a' , { 'p' ,   -1 } , // 28 
				 'b' , { '�' ,   -1 } , // 29 
				 'c' , { 'O' ,   -1 } , // 30 

				 'd' , { 'L' ,   -1 } , // 31 
				 'e' , { '�' ,   -1 } , // 32 
				 'f' , { 'e' ,   -1 } , // 33 

				 'g' , { '~' ,   -1 } , // 34 
				 'h' , { 'l' ,   -1 } , // 35 
				 'i' , { 'h' ,   -1 } , // 36 

				 'k' , { '�' ,   -1 } , // 37 
				 'l' , { '�' ,   -1 } , // 38 
				 'm' , { 'M' ,   -1 } , // 39 
				 'n' , { 'U' ,   -1 } , // 1 
				 'o' , { '~' ,  '�' ,   -1 } , // 2 
				 'p' , { '�' ,  '�' ,   -1 } , // 3 

				 'q' , { '�' ,   -1 } , // 4 
				 'r' , { '�' ,   -1 } , // 5 
				 'q' , { 's' ,  '�' ,  '�' ,   -1 } , // 6 

				 'r' , { '�' ,  '�' ,  '�' ,   -1 } , // 7 
				 't' , { 'w' ,   -1 } , // 8 
				 'u' , { '�' ,   -1 } , // 9 

				 't' , { '�' ,  ']' ,   -1 } , // 10 
				 'v' , { '�' ,   -1 } , // 11 
				 'w' , { '�' ,   -1 } , // 12 

				 'x' , { '�' ,  'S' ,   -1 } , // 13 
				 'y' , { '|' ,  'S' ,   -1 } , // 14 
				 'z' , { '�' ,   -1 } , // 15 

				 '�' , { '|' ,   -1 } , // 16 
				 'z' , { 's' ,  '�' ,  '�' ,   -1 } , // 17 
				 '�' , { '�' ,  '|' ,  '�' ,   -1 } , // 18 

				 '�' , { '�' ,   -1 } , // 19 
				 '�' , { '`' ,   -1 } , // 20 
				 '�' , { 'F' ,   -1 } , // 21 

				 '�' , { '�' ,   -1 } , // 22 
				 '�' , { '�' ,   -1 } , // 23 
				 '�' , { '�' ,   -1 } , // 24 

				 '�' , { '[' ,   -1 } , // 25 
				 '�' , { 's' ,  '�' ,  '�' ,   -1 } , // 26 
				 '�' , { '�' ,  '[' ,  '�' ,   -1 } , // 27 

				 '�' , { '�' ,  '�' ,  '�' ,  '�' ,  '�' ,   -1 } , // 28 
				 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 29 
				 'A' , { 'i' ,  '�' ,  '�' ,  '@' ,  '�' ,   -1 } , // 30 

				 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 31 
				 'g' , { '~' ,   -1 } , // 32 
				 'h' , { '�' ,   -1 } , // 33 

				 '�' , { '�' ,   -1 } , // 34 
				 '�' , { '�' ,   -1 } , // 35 
				 '�' , { '�' ,   -1 } , // 36 

				 '�' , { 'z' ,   -1 } , // 37 
				 '�' , { '�' ,   -1 } , // 38 
				 '�' , { 'F' ,  '�' ,   -1 } , // 39 

				 '�' , { '�' ,  '�' ,   -1 } , // 40 
				 '�' , { '�' ,   -1 } , // 41 
				 '�' , { '�' ,   -1 } , // 42 

				 '�' , { 'B' ,   -1 } , // 43 
				 '�' , { '�' ,   -1 } , // 44 
				 '�' , { '{' ,   -1 } , // 45 

				 '�' , { '�' ,   -1 } , // 46 
				 '�' , { 'y' ,   -1 } , // 47 
				 '�' , { '�' ,   -1 } , // 48 

				 '�' , { '�' ,   -1 } , // 49 
				 '�' , { '�' ,   -1 } , // 50 
				 '�' , { 'A' ,   -1 } , // 51 

				 '�' , { '�' ,   -1 } , // 52 
				 '�' , { '�' ,   -1 } , // 53 
				 '�' , { '�' ,   -1 } , // 54 

				 '�' , { '�' ,   -1 } , // 55 
				 '�' , { '�' ,   -1 } , // 56 
				 '�' , { '�' ,   -1 } , // 57 

				 '�' , { '�' ,   -1 } , // 58 
				 '�' , { 'd' ,   -1 } , // 59 
				 '�' , { 'R' ,   -1 } , // 60 

				 '�' , { '�' ,   -1 } , // 61 
				 '�' , { '�' ,   -1 } , // 62 
				 '�' , { 'a' ,   -1 } , // 63 

				 '�' , { '�' ,   -1 } , // 64 
				 '�' , { 'H' ,   -1 } , // 65 
				 '�' , { '�' ,   -1 } , // 66 

				 '�' , { 'N' ,   -1 } , // 67 
				 '�' , { '�' ,   -1 } , // 68 
				 '�' , { '�' ,   -1 } , // 69 

				 '�' , { 'j' ,   -1 } , // 70 
				 '�' , { 'Z' ,   -1 } , // 71 
				 '�' , { 't' ,   -1 } , // 72 

				 '�' , { 'v' ,   -1 } , // 73 
				 '�' , { '�' ,   -1 } , // 74 
				 '�' , { 'x' ,   -1 } , // 75 

				 '�' , { '�' ,   -1 } , // 76 
				 '�' , { '�' ,   -1 } , // 77 
				 '�' , { '�' ,   -1 } , // 78 

				 '�' , { 'T' ,   -1 } , // 79 
				 '�' , { '�' ,   -1 } , // 80 
				 '�' , { '�' ,   -1 } , // 81 

				 '�' , { '�' ,   -1 } , // 82 
				 '�' , { '�' ,   -1 } , // 1 
				 '�' , { 'C' ,   -1 } , // 2 
				 '�' , { '�' ,   -1 } , // 3 

				 '�' , { '�' ,   -1 } , // 4 
				 '�' , { 'I' ,   -1 } , // 5 
				 '�' , { 'X' ,   -1 } , // 6 

				 '�' , { '�' ,   -1 } , // 7 
				 '�' , { '�' ,   -1 } , // 8 
				 '�' , { '�' ,   -1 } , // 9 

				 '�' , { '}' ,   -1 } , // 10 
				 '�' , { 'E' ,   -1 } , // 11 
				 '�' , { 'W' ,   -1 } , // 12 

				 '�' , { '�' ,   -1 } , // 13 
				 '1' , { '�' ,   -1 } , // 14 
				 '2' , { '�' ,   -1 } , // 15 

				 '3' , { '�' ,   -1 } , // 16 
				 '4' , { '�' ,   -1 } , // 17 
				 '5' , { 'D' ,   -1 } , // 18 

				 '6' , { '�' ,   -1 } , // 19 
				 '7' , { '<' ,   -1 } , // 20 
				 '8' , { '>' ,   -1 } , // 21 

				 '9' , { 'k' ,   -1 } , // 22 
				 '0' , { 'c' ,   -1 } , // 23 
				 '-' , { '�' ,   -1 } , // 24 

				 '=' , { '+' ,   -1 } , // 25 
				 '!' , { '=' ,   -1 } , // 26 
				 '@' , { '!' ,   -1 } , // 27 

				 '%' , { '%' ,   -1 } , // 28 
				 '*' , { '*' ,   -1 } , // 29 
				 '(' , { '(' ,   -1 } , // 30 

				 ')' , { ')' ,   -1 } , // 31 
				 '|' , { '&' ,   -1 } , // 32 
				 ';' , { ';' ,   -1 } , // 33 

				 '`' , { '"' ,   -1 } , // 34 
				 ':' , { ':' ,   -1 } , // 35 
				 ',' , { ',' ,   -1 } , // 36 

				 '.' , { '.' ,   -1 } , // 37 
				 '/' , { '/' ,   -1 } , // 38 
				 '?' , { '?' ,   -1 } , // 39 

				 '�' , { 's' ,  'F' ,  'i' ,   -1 } , // 40 
				 '�' , { '�' ,  '�' ,  'i' ,   -1 } , // 41 
				 '�' , { '\'' ,   -1 } , // 42 
 };

struct Conv_Tab3
{
	char vSrg;
	char vKump[8];
}Surabhi[149] = {
					 'A' , { 'S' , 'U','D','H','E','E','R',  -1 } , // 1 
 'B' , { 'H' ,'A','S','S','A', 'n' ,   -1 } , // 2 
 'C' , { 'E' ,   -1 } , // 3 

 'D' , { 'F' ,   -1 } , // 4 
 'E' , { 'G' ,   -1 } , // 5 
 'F' , { 'H' ,   -1 } , // 6 

 'G' , { 'I' ,   -1 } , // 7 
 'H' , { 'J' ,   -1 } , // 8 
 'I' , { 'K' ,   -1 } , // 9 

 'J' , { 'L' ,   -1 } , // 10 
 'K' , { 'M' ,   -1 } , // 11 
 'L' , { 'N' ,   -1 } , // 12 

 'M' , { 'O' ,   -1 } , // 13 
 'N' , { 'A' ,   -1 } , // 14 
 'O' , { 'B' ,   -1 } , // 15 

 'P' , { 'P' ,   -1 } , // 16 
 'Q' , { 'Q' ,   -1 } , // 17 
 'R' , { '�' ,   -1 } , // 18 

 'S' , { '�' ,  '�' ,   -1 } , // 19 
 'T' , { '�' ,  '�' ,   -1 } , // 20 
 'U' , { 'R' ,   -1 } , // 21 

 'V' , { 'S' ,   -1 } , // 22 
 'W' , { 'T' ,   -1 } , // 23 
 'X' , { '�' ,   -1 } , // 24 

 'Y' , { 'U' ,   -1 } , // 25 
 'Z' , { 'V' ,   -1 } , // 26 
 'a' , { '�' ,   -1 } , // 27 

 'b' , { 'W' ,   -1 } , // 28 
 'c' , { 'X' ,   -1 } , // 29 
 'd' , { '�' ,   -1 } , // 30 

 'e' , { 'Y' ,   -1 } , // 31 
 'f' , { '�' ,   -1 } , // 32 
 'g' , { 'Z' ,   -1 } , // 33 

 'h' , { 'a' ,   -1 } , // 34 
 'i' , { '�' ,   -1 } , // 35 
 'j' , { '�' ,  '�' ,   -1 } , // 36 

 'm' , { '�' ,   -1 } , // 37 
 'k' , { 'b' ,   -1 } , // 38 
 'l' , { 'c' ,   -1 } , // 39 

 'n' , { 'd' ,   -1 } , // 40 
 'o' , { 'e' ,   -1 } , // 41 
 'p' , { 'f' ,   -1 } , // 42 

 'q' , { '�' ,   -1 } , // 43 
 'r' , { 'h' ,   -1 } , // 44 
 's' , { '�' ,   -1 } , // 45 

 't' , { 'k' ,   -1 } , // 46 
 'u' , { '�' ,   -1 } , // 47 
 'v' , { 'l' ,   -1 } , // 48 

 'w' , { 'm' ,   -1 } , // 49 
 'x' , { 'n' ,   -1 } , // 50 
 'y' , { '�' ,   -1 } , // 51 

 'z' , { '�' ,  '�' ,   -1 } , // 52 
 '�' , { 'o' ,   -1 } , // 53 
 '�' , { 'p' ,   -1 } , // 54 

 '�' , { '�' ,   -1 } , // 55 
 '�' , { 'q' ,   -1 } , // 56 
 '�' , { 'r' ,   -1 } , // 57 

 '�' , { '�' ,   -1 } , // 58 
 '�' , { 't' ,   -1 } , // 59 
 '�' , { 'u' ,   -1 } , // 60 

 '�' , { 't' ,  '�' ,   -1 } , // 61 
 '�' , { '�' ,   -1 } , // 62 
 '�' , { 'v' ,   -1 } , // 63 

 '�' , { 'w' ,   -1 } , // 64 
 '�' , { '�' ,   -1 } , // 65 
 '�' , { '�' ,  '�' ,   -1 } , // 66 

 '�' , { '�' ,  '�' ,   -1 } , // 67 
 '�' , { '�' ,  '�' ,   -1 } , // 68 
 '�' , { '�' ,  '�' ,   -1 } , // 69 

 '�' , { '�' ,  '�' ,   -1 } , // 70 
 '�' , { 'x' ,   -1 } , // 71 
 '�' , { 'y' ,   -1 } , // 72 

 '�' , { '�' ,   -1 } , // 73 
 '�' , { 'z' ,   -1 } , // 74 
 '�' , { '�' ,   -1 } , // 75 

 '�' , { '�' ,   -1 } , // 76 
 '�' , { '�' ,   -1 } , // 77 
 '�' , { '�' ,   -1 } , // 78 

 '�' , { '�' ,   -1 } , // 79 
 '�' , { '�' ,   -1 } , // 80 
 '�' , { '�' ,   -1 } , // 81 

 '�' , { '�' ,   -1 } , // 82 
 '�' , { '�' ,  '�' ,   -1 } , // 83 
 '�' , { '�' ,   -1 } , // 84 

 '�' , { '�' ,   -1 } , // 85 
 '�' , { '�' ,   -1 } , // 86 
 '�' , { '�' ,   -1 } , // 87 

 '�' , { '�' ,   -1 } , // 88 
 '�' , { '�' ,   -1 } , // 89 
 '�' , { '�' ,   -1 } , // 90 

 '�' , { 'g' ,   -1 } , // 91 
 '�' , { 'h' ,   -1 } , // 92 
 '�' , { '�' ,   -1 } , // 93 

 '�' , { '�' ,   -1 } , // 94 
 '�' , { '�' ,   -1 } , // 95 
 '�' , { '�' ,  '�' ,   -1 } , // 96 

 '�' , { '�' ,   -1 } , // 97 
 '�' , { '�' ,   -1 } , // 98 
 '�' , { '�' ,   -1 } , // 99 

 '�' , { '�' ,   -1 } , // 100 
 '�' , { '�' ,   -1 } , // 101 
 '�' , { '�' ,   -1 } , // 102 

 '�' , { '�' ,   -1 } , // 103 
 '�' , { '�' ,   -1 } , // 104 
 '�' , { '�' ,   -1 } , // 105 

 '�' , { '�' ,   -1 } , // 106 
 '�' , { '�' ,   -1 } , // 107 
 '�' , { '�' ,   -1 } , // 108 

 '�' , { '�' ,   -1 } , // 109 
 '�' , { '�' ,   -1 } , // 110 
 '�' , { '�' ,   -1 } , // 111 

 '�' , { '�' ,   -1 } , // 112 
 '�' , { '�' ,   -1 } , // 113 
 '�' , { '�' ,  '�' ,   -1 } , // 114 

 '�' , { '�' ,   -1 } , // 115 
 '�' , { '�' ,   -1 } , // 116 
 '�' , { '�' ,   -1 } , // 117 

 '�' , { '�' ,   -1 } , // 118 
 '�' , { '�' ,   -1 } , // 119 
 '�' , { '�' ,   -1 } , // 120 

 '�' , { '�' ,   -1 } , // 121 
 '�' , { '�' ,   -1 } , // 122 
 '�' , { 'i' ,   -1 } , // 123 

 '�' , { '�' ,   -1 } , // 124 
 '�' , { '�' ,   -1 } , // 125 
 '�' , { '�' ,   -1 } , // 126 

 '�' , { '�' ,   -1 } , // 127 
 '�' , { '�' ,   -1 } , // 128 
 '�' , { '�' ,   -1 } , // 129 

 '�' , { '�' ,   -1 } , // 130 
 '�' , { '�' ,   -1 } , // 131 
 '�' , { '�' ,   -1 } , // 132 

 '�' , { '�' ,   -1 } , // 133 
 '�' , { '�' ,   -1 } , // 134 
 '�' , { '�' ,   -1 } , // 135 

 '�' , { '�' ,   -1 } , // 136 
 '�' , { '�' ,   -1 } , // 137 
// '�' , { '�' ,  'q' ,  's' ,   -1 } , // 138 

 '�' , { '�' ,  '�' ,   -1 } , // 139 
 '�' , { 'z' ,  's' ,   -1 } , // 140 
 '�' , { '�' ,  '�' ,   -1 } , // 141 

 '�' , { '�' ,  '�' ,  's' ,   -1 } , // 142 
 '�' , { '�' ,  '�' ,   -1 } , // 143 
 '�' , { '�' ,  '�' ,  's' ,   -1 } , // 144 

 '�' , { '�' ,  '�' ,   -1 } , // 145 
 '�' , { '�' ,  'r' ,  '�' ,   -1 } , // 146 
 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 147 

 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 148 
 '�' , { '�' ,  '�' ,  '�' ,   -1 } , // 149 

					};
struct Conv_Tab4
{
	char vSrg;
	char vKump[8];
}Akruthi[175] = {	 'A' , { 'h' ,   -1 } , // 1 
				 'B' , { '�' ,   -1 } , // 2 
				 'C' , { '"' ,   -1 } , // 3 

				 'D' , { '�' ,   -1 } , // 4 
				 'E' , { '$' ,   -1 } , // 5 
				 'F' , { '&' ,   -1 } , // 6 

				 'G' , { '\'' ,   -1 } , // 7 
				 'H' , { 'g' ,   -1 } , // 8 
				 'I' , { '�' ,  't' ,  'l' ,   -1 } , // 9 

				 'J' , { '�' ,   -1 } , // 10 
				 'K' , { '~' ,   -1 } , // 11 
				 'L' , { '�' ,   -1 } , // 12 

				 'M' , { '�' ,   -1 } , // 13 
				 'N' , { '�' ,   -1 } , // 14 
				 'O' , { 'n' ,   -1 } , // 15 

				 'P' , { '�' ,   -1 } , // 16 
				 'Q' , { '�' ,   -1 } , // 17 
				 'R' , { 'V' ,   -1 } , // 18 

				 'S' , { '�' ,   -1 } , // 19 
				 'T' , { '�' ,   -1 } , // 20 
				 'U' , { '�' ,   -1 } , // 21 

				 'V' , { 'e' ,   -1 } , // 22 
				 'W' , { '�' ,   -1 } , // 23 
				 'W' , { '�' ,  '�' ,   -1 } , // 24 

				 'X' , { '�' ,   -1 } , // 25 
				 'Y' , { 'z' ,   -1 } , // 26 
				 'Z' , { '�' ,   -1 } , // 27 

				 'a' , { '�' ,   -1 } , // 28 
				 'b' , { '�' ,   -1 } , // 29 
				 'c' , { '�' ,   -1 } , // 30 

				 'd' , { '�' ,   -1 } , // 31 
				 'e' , { 'E' ,   -1 } , // 32 
				 'f' , { '�' ,   -1 } , // 33 

				 'g' , { '!' ,   -1 } , // 34 
				 'h' , { '�' ,   -1 } , // 35 
				 'i' , { 'X' ,   -1 } , // 36 
				 'k' , { '�' ,   -1 } , // 1 
				 'l' , { '�' ,   -1 } , // 2 
				 'm' , { '�' ,   -1 } , // 3 
				 'n' , { '�' ,   -1 } , // 1 
				 'o' , { '�' ,   -1 } , // 2 
				 'p' , { '�' ,   -1 } , // 3 

				 'q' , { '�' ,   -1 } , // 4 
				 'r' , { 'f' ,   -1 } , // 5 
				 'q' , { 's' ,  '[' ,   -1 } , // 6 

				 'r' , { 'f' ,   -1 } , // 7 
				 'r' , { '�' ,  '�' ,   -1 } , // 1 
				 't' , { '�' ,   -1 } , // 2 
				 'u' , { 'I' ,   -1 } , // 3 

				 't' , { '�' ,  '�' ,   -1 } , // 4 
				 'v' , { 'd' ,   -1 } , // 5 
				 'v' , { '�' ,  '�' ,   -1 } , // 6 

				 'x' , { '�' ,   -1 } , // 7 
				 'y' , { '�' ,   -1 } , // 8 
				 'z' , { '|' ,   -1 } , // 9 

				 '�' , { '�' ,   -1 } , // 10 
				 'z' , { 's' ,  '�' ,   -1 } , // 11 
				 '�' , { '�' ,  '�' ,   -1 } , // 12 

				 '�' , { '�' ,   -1 } , // 13 
				 '�' , { '�' ,   -1 } , // 14 
				 '�' , { '�' ,   -1 } , // 15 

				 '�' , { 'P' ,   -1 } , // 16 
				 '�' , { '�' ,   -1 } , // 17 
				 '�' , { '�' ,   -1 } , // 18 
				 '�' , { 's' ,  '�' ,   -1 } , // 1 
				 '�' , { '�' ,  '�' ,   -1 } , // 2 
				 '�' , { '�' ,  '�' ,  '@' ,  '*' ,  'l' ,   -1 } , // 3 

				 '�' , { '�' ,  'W' ,  'l' ,   -1 } , // 4 
				 'A' , { 'i' ,  '�' ,  '�' ,  '�' ,  'l' ,   -1 } , // 5 
				 '�' , { '�' ,  '�' ,  'l' ,   -1 } , // 6 

				 'g' , { '!' ,   -1 } , // 7 
				 'h' , { 'y' ,   -1 } , // 8 
				 '�' , { 'm' ,   -1 } , // 9 

				 '�' , { '#' ,   -1 } , // 10 
				 '�' , { '�' ,   -1 } , // 11 
				 '�' , { '@' ,  '�' ,   -1 } , // 12 

				 '�' , { 'W' ,   -1 } , // 13 
				 '�' , { '�' ,   -1 } , // 14 
				 '�' , { 'O' ,   -1 } , // 15 

				 '�' , { '�' ,   -1 } , // 16 
				 '�' , { '�' ,   -1 } , // 17 
				 '�' , { '�' ,   -1 } , // 18 

				 '�' , { '�' ,   -1 } , // 19 
				 '�' , { 'A' ,   -1 } , // 20 
				 '�' , { '�' ,   -1 } , // 21 

				 '�' , { '\\' ,   -1 } , // 22 
				 '�' , { 'D' ,   -1 } , // 23 
				 '�' , { '�' ,   -1 } , // 24 

				 '�' , { '�' ,   -1 } , // 25 
				 '�' , { '�' ,   -1 } , // 26 
				 '�' , { '_' ,   -1 } , // 27 

				 '�' , { '�' ,   -1 } , // 28 
				 '�' , { 'o' ,   -1 } , // 29 
				 '�' , { '�' ,   -1 } , // 30 

				 '�' , { 'K' ,   -1 } , // 31 
				 '�' , { '�' ,   -1 } , // 32 
				 '�' , { 'k' ,   -1 } , // 33 

				 '�' , { '�' ,   -1 } , // 34 
				 '�' , { 's' ,   -1 } , // 35 
				 '�' , { 'T' ,   -1 } , // 36 

				 '�' , { '�' ,   -1 } , // 37 
				 'V' , {  -1 } , // 38 
				 '�' , { '�' ,   -1 } , // 1 
				 '�' , { 'w' ,   -1 } , // 2 
				 '�' , { '�' ,   -1 } , // 3 

				 '�' , { 'a' ,   -1 } , // 4 
				 '�' , { '�' ,   -1 } , // 5 
				 '�' , { '�' ,   -1 } , // 6 

				 '�' , { '�' ,   -1 } , // 7 
				 '�' , { '�' ,   -1 } , // 8 
				 '�' , { '^' ,   -1 } , // 9 

				 '�' , { '}' ,   -1 } , // 10 
				 '�' , { '�' ,   -1 } , // 11 
				 '�' , { 'C' ,   -1 } , // 12 

				 '�' , { '�' ,   -1 } , // 13 
				 '�' , { 'r' ,   -1 } , // 14 
				 '�' , { '�' ,   -1 } , // 15 

				 '�' , { 'u' ,   -1 } , // 16 
				 '�' , { '<' ,   -1 } , // 17 
				 '�' , { '�' ,   -1 } , // 18 

				 '�' , { 'S' ,   -1 } , // 19 
				 '�' , { '*' ,   -1 } , // 20 
				 '�' , { 'J' ,   -1 } , // 21 

				 '�' , { '�' ,   -1 } , // 22 
				 '�' , { 'l' ,   -1 } , // 23 
				 '�' , { '�' ,   -1 } , // 24 
				 '�' , { 'S' ,   -1 } , // 1 
				 '�' , { '�' ,   -1 } , // 2 
				 '�' , { '*' ,   -1 } , // 3 

				 '�' , { 'J' ,   -1 } , // 4 
				 '�' , { '�' ,   -1 } , // 5 
				 '�' , { 'l' ,   -1 } , // 6 

				 '�' , { 'l' ,   -1 } , // 7 
				 '�' , { '�' ,   -1 } , // 1 
				 '�' , { '�' ,   -1 } , // 2 
				 '�' , { '�' ,   -1 } , // 3 

				 '�' , { '�' ,   -1 } , // 4 
				 '�' , { 'x' ,   -1 } , // 5 
				 '�' , { '�' ,   -1 } , // 6 

				 '�' , { 'F' ,   -1 } , // 7 
				 '�' , { 'B' ,   -1 } , // 8 
				 '�' , { 'v' ,   -1 } , // 9 

				 '1' , { '1' ,   -1 } , // 10 
				 '2' , { '2' ,   -1 } , // 11 
				 '3' , { '3' ,   -1 } , // 12 

				 '4' , { '4' ,   -1 } , // 13 
				 '5' , { '5' ,   -1 } , // 14 
				 '6' , { '6' ,   -1 } , // 15 

				 '7' , { '7' ,   -1 } , // 16 
				 '8' , { '8' ,   -1 } , // 17 
				 '9' , { '9' ,   -1 } , // 18 

				 '0' , { '0' ,   -1 } , // 19 
				 '=' , { '=' ,   -1 } , // 20 
				 '(' , { '(' ,   -1 } , // 21 
				 '[' , { '�' ,  '�' ,   -1 } , // 1 
				 ']' , { 'G' ,  'Q' ,   -1 } , // 2 
				 ';' , { ';' ,   -1 } , // 3 

				 '`' , { '�' ,   -1 } , // 4 
				 ':' , { ':' ,   -1 } , // 5 
				 ',' , { ',' ,   -1 } , // 6 

				 '.' , { '.' ,   -1 } , // 7 
				 '/' , { '/' ,   -1 } , // 8 
				 '?' , { '?' ,   -1 } , // 9 

				 'j' , { 'y' ,   -1 } , // 10 
				 '�' , { 's' ,  'M' ,   -1 } , // 11 
				 '�' , { '�' ,  '�' ,  'i' ,   -1 } , // 12 

				 '�' , { '\'' ,   -1 } , // 13 
				 'j' , { 'y' ,   -1 } , // 1 
				 '�' , { 's' ,  'M' ,   -1 } , // 2 
				 '�' , { '�' ,  '�' ,   -1 } , // 3 

				 '�' , { '�' ,   -1 } , // 4 
				 '�' , { '�' ,   -1 } , // 1 
				 ')' , { ')' ,   -1 } , // 2 
				 '_' , { '�' ,   -1 } , // 3 

				 '`' , { '�' ,   -1 } , // 4 
				};

int Text_Converter::Srg_To_Kuvempu(const char* pszSRCFile,const char* pszDSTFile)
{
			found = FALSE;

			fstream out(pszDSTFile , ios::out );
			fstream in (pszSRCFile , ios::in  );
			
			while(in.read((char * ) &fchr , sizeof fchr))
			{
				found = FALSE;
				for(i=0;i<150;i++)
				{
					if( Srg[i].vSrg == fchr ) 
					{   
						j=0;
						found  = TRUE;
						while(Srg[i].vKump[j] != -1)
						{	
							out.write((char *) &Srg[i].vKump[j] ,sizeof Srg[i].vKump[j]);
							j++;
						}
					}
				}
				if(found == FALSE)
				{
					out.write((char *) &fchr ,sizeof fchr);
				}
			}
			//::MessageBox(NULL,"File Conversion OK","SRG To KUVEMPU",MB_OK);
			bRet = TRUE;
	out.close();
	in.close();
	return bRet;
}


int Text_Converter::SreeLipi_To_Kuvempu(const char* pszSRCFile,const char* pszDSTFile)
{

			fstream out(pszDSTFile , ios::out );
			fstream in (pszSRCFile , ios::in  );
			
			while(in.read((char * ) &fchr , sizeof fchr))
			{
				for(i=0;i<170;i++)
				{
					found = FALSE;	
				  if( Sree[i].vSrg == fchr ) 
					{   
						j=0;
						found = TRUE;
						while(Sree[i].vKump[j] != -1)
						{	
							out.write((char *) &Sree[i].vKump[j] ,sizeof Sree[i].vKump[j]);
							j++;
						}
					}
				}
				if(!found)
				{
					out.write((char *) fchr ,sizeof fchr);
				}
			}

			//::MessageBox(NULL,"File Conversion OK","SRG To KUVEMPU",MB_OK);
			bRet = TRUE;
	out.close();
	in.close();
	return bRet;
}


int Text_Converter::Surabhi_To_Kuvempu(const char* pszSRCFile,const char* pszDSTFile)
{
			found = FALSE;

			fstream out(pszDSTFile , ios::out );
			fstream in (pszSRCFile , ios::in  );
			
			while(in.read((char * ) &fchr , sizeof fchr))
			{
				found = FALSE;
				for(i=0;i<150;i++)
				{
					if( Surabhi[i].vSrg == fchr ) 
					{   
						j=0;
						found  = TRUE;
						while(Surabhi[i].vKump[j] != -1)
						{	
							out.write((char *) &Surabhi[i].vKump[j] ,sizeof Surabhi[i].vKump[j]);
							j++;
						}
					}
				}
				if(found == FALSE)
				{
					out.write((char *) &fchr ,sizeof fchr);
				}
			}
			//::MessageBox(NULL,"File Conversion OK","SRG To KUVEMPU",MB_OK);
			bRet = TRUE;
	out.close();
	in.close();
	return bRet;
}

int Text_Converter::Akruthi_To_Kuvempu(const char* pszSRCFile,const char* pszDSTFile)
{
			

			fstream out(pszDSTFile , ios::out );
			fstream in (pszSRCFile , ios::in  );
			
			while(in.read((char * ) &fchr , sizeof fchr))
			{
				for(i=0;i<175;i++)
				{
					found = FALSE;	
					if( Akruthi[i].vSrg == fchr ) 
					{   
						j=0;
						found = TRUE;
						while(Akruthi[i].vKump[j] != -1)
						{	
							out.write((char *) &Akruthi[i].vKump[j] ,sizeof Akruthi[i].vKump[j]);
							j++;
						}
					}
				}
					if(!found)
				{
					out.write((char *) fchr ,sizeof fchr);
				}
			}

			//::MessageBox(NULL,"File Conversion OK","SRG To KUVEMPU",MB_OK);
			bRet = TRUE;
	out.close();
	in.close();
	return bRet;
}