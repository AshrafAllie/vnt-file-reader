//Date:   28June2013Fri19:17
//File:   vnt_file_reader.c
//Author: Ashraf
//Email:  ashraf.allie01@gmail.com
/*Desc:   This program reads in a vnt file and displays its contents. 




    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include<stdio.h>

int main(int argc, char *argv[])
{
 FILE *fp;
 int c;
 int len;
 unsigned char hex[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
 unsigned char is_hex = 0;

 if (argc == 2)
 {
  fp = fopen(argv[1], "r");
  if (fp)
  {
   fseek(fp, -54, SEEK_END);
   len = ftell(fp);
   fseek(fp, 71, SEEK_SET);
   while (ftell(fp) != len)
   {
    c = fgetc(fp);
 
    if (is_hex == 1)
    {
     if (c == '\n')
     {
      is_hex = 0;
      continue;
     }
     else if ((c >= '0') && (c <= '9') ||
              (c >= 'A') && (c <= 'F')
             )
            if (hex[0] == '\0')
              hex[0] = c;
            else if (hex[1] == '\0')
            {
             hex[1] = c;
             if ((hex[0] == '0') && (hex[1] == 'A'))
               printf("\n");
             else if ((hex[0] == '3') && (hex[1] == 'D'))
                    printf("=");
             else if ((hex[0] == '2') && (hex[1] == 'E'))
                    printf(".");
             /*
             else if ()
                    printf("€");
             */

             if ((hex[0] != 'C') && (hex[1] != '2') ||
                 (hex[0] != 'E') && (hex[1] != '2')
                )
             {
              hex[0] = '\0';
              hex[1] = '\0';
              is_hex = 0;
              continue;
             }
            }
            else if ((hex[0] == 'C') && (hex[1] == '2'))
            {
             if (hex[2] == '\0')
               hex[2] = c;
             else if (hex[3] == '\0')
             {
              hex[3] = c;

              if ((hex[2] == 'A') && (hex[3] == '3'))
                printf("£");
              else if ((hex[2] == 'A') && (hex[3] == '7'))
                     printf("§");
              else if ((hex[2] == 'A') && (hex[3] == '5'))
                     printf("¥");
              else if ((hex[2] == 'B') && (hex[3] == 'F'))
                     printf("¿");
              else if ((hex[2] == 'A') && (hex[3] == '1'))
                     printf("¡");
              else if ((hex[2] == 'A') && (hex[3] == '4'))
                     printf("¤");
              else if ((hex[2] == 'A') && (hex[3] == '2'))
                     printf("¢");
              else if ((hex[2] == 'A') && (hex[3] == 'B'))
                     printf("«");
              else if ((hex[2] == 'B') && (hex[3] == 'B'))
                     printf("»");
              else if ((hex[2] == 'A') && (hex[3] == 'E'))
                     printf("®");
              else if ((hex[2] == 'A') && (hex[3] == '9'))
                     printf("©");
              else if ((hex[2] == 'B') && (hex[3] == '0'))
                     printf("°");

              hex[0] = '\0';
              hex[1] = '\0';
              hex[2] = '\0';
              hex[3] = '\0';
              is_hex = 0;
              continue;
             }
            }
            else if ((hex[0] == 'E') && (hex[1] == '2'))
            {
             if (hex[2] == '\0')
               hex[2] = c;
             else if (hex[3] == '\0')
                    hex[3] = c;
             else if (hex[4] == '\0')
                    hex[4] = c;
             else if (hex[5] == '\0')
             {
              hex[5] = c;

              if ((hex[2] == '8') && (hex[3] == '2') &&
                  (hex[4] == 'A') && (hex[5] == 'C')
                 )
                printf("€");


              hex[0] = '\0';
              hex[1] = '\0';
              hex[2] = '\0';
              hex[3] = '\0';
              hex[4] = '\0';
              hex[5] = '\0';
              is_hex = 0;
              continue;
              
             }
            }
    }
 
    if (c == '=')
      is_hex = 1;
 
    if (is_hex == 0)
      printf("%c", c);
   }
   
   fclose(fp);
   printf("\n");
  }
  else printf("Error file not read\n");
 
 }
 return 0;
}
