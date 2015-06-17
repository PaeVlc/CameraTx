#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void charToBinary(char c,int output[]);
void textToBinary(char texto[], char binary[]);
void saveBinaryInFile(char binary[]);
int size;
int main(void)
{
char *data;
char texto[1000];
printf("%s%c%c\n",
"Content-Type:text/html;charset=iso-8859-1",13,10);
printf("<HTML><HEAD>\n");
printf("<TITLE>Saving to database...</TITLE>\n");
printf("<link rel=\"stylesheet\" href=\"../../css/style_minified.css\">\n");
printf("</HEAD><BODY >\n");
data = getenv("QUERY_STRING");
if(data == NULL)
  printf("<P>Error! Error in passing data from form to script.");
  printf("<div class=\"navbar navbar-inverse navbar-fixed-top\" role=\"navigation\">");
       printf(" <div class=\"container\">");
       printf("   <div class=\"navbar-header\">");
         printf("   <div id=\"bs\"> <button id=\"back\" onclick=\"history.back()\"  type= \"submit\" name=\"logout\" value=\"logout\"  >Back</button></div>");

       printf("   </div>");
  printf("<center><h2 style=\"color:white\" >Visible Light Communication</h2></center>");
       printf(" </div>");
      printf("</div>");
sscanf(data,"m=%s",texto);
size=strlen(texto)*8;
char binary[size];

textToBinary(texto, binary);
binary[size]=0x00;

saveBinaryInFile(binary);


printf("<h2 style=\"color:white\">The text sent is: %s<br></h2>",texto);
printf("<h4 style=\"color:white\">Corresponding binary sequence is: %s<br></h4>", binary);
 printf("<div class=\"navbar navbar-inverse navbar-fixed-bottom\" role=\"navigation\">");
       printf("	<div class=\"container\">");
		 printf("<center><h5 style=\"color:white\" > VLC &copy; PAE-2015</h5></center>");
      printf("	 </div>");
     printf("	</div>");
    printf("</body></html>\n");

return 0;
}
void charToBinary(char c,int output[])
{
    int i;
    for (i = 0; i < 7; i++)
    {
        output[7-i] = (c >> i) & 1;
        
    }
	output[0]=0;
}
void textToBinary(char texto[], char *binary)
{
 
    int longTexto=strlen(texto);
    int output[8];
    int i=0;
    for (i=0; i<longTexto; i++)
    {

        charToBinary(texto[i], output);
	int j=0;
        for(j=0;j<8;j++)
        {
            binary[i*8+j]=output[j]+'0';
           // printf("%c",binary[j+i*7]);
        }
        //printf("-----");

    }

}

void saveBinaryInFile(char *binary){
    FILE *fp;
	int i=0;

    fp = fopen ( "DBtransmitter.txt", "wt" );
    
	for(i=0;i<size;i++){
	fprintf(fp, "%c", binary[i]);
    }
fclose ( fp );
    

}



