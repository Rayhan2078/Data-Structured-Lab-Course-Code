#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
int available(char *word, char ch);
int main()
{

  char ch, thing[size];
int have;
  printf("Please Enter a string : ");
  gets(thing);
  printf("Please Enter which charecter you want to search : ");
  scanf("%c", &ch);
  have = available(thing, ch);
  if (have == 1)
  {
    printf("we found the charetcer!");
  }
  else
  {
    printf("we didn't found it!");
  }
}
int available(char *word, char ch)
{
  int present = 0, count = 0, space = 0;
  while (*word != NULL)
  {
    count++;
    if (ch == *word)
    {
      present = 1;
      break;
    }
    word++;
  }
  printf("\nfound in %d position\n", count);
  return present;
}
\\

#include <stdio.h>
#include <string.h>
#define size 100
int available(char have[], int high, int low, char search);
int main()
{
    int size_word, i, j, low = 0, high;
    char a[size], temp, search_word;
    printf("Please enter a string : ");
    gets(a);
    high = (strlen(a) - 1);
    // this is for comparing capital letter
    for (i = 0; i < strlen(a); i++)
    {
        for (j = i + 1; j < strlen(a); j++)
        {
            if (a[j] >= 65 && a[j] <= 90)
            {
                if (a[j + 1] >= 65 && a[j + 1] <= 90)
{
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }

            // this is for comparing small letter

            if (a[j] >= 97 && a[j] <= 122)
            {
                if (a[j + 1] >= 97 && a[j + 1] <= 122)
                {
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
        }
    }

    printf("Please Enter which Word you want to search : ");
    scanf("%c", &search_word);
    int stock;
    stock = available(a, high, low, search_word);
    if (stock == -1)
    {
        printf("sorry we didn't found it!");
    }
    else

    {
        printf("yes! we found it at %d position",stock);
    }
}
int available(char have[], int high, int low, char search){
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (have[mid] == search)
            return mid;
        else if (have[mid] < search)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
\\

#include <stdio.h>
#include <string.h>
#define size 100
int search(char know[], int start, int highest, char want);
int main()
{
    int len, pos, start = 0;
    char word[size], ch;
    printf("Please Enter a string : ");
    gets(word);
    len = strlen(word);
    printf("Please Enter which charecter you want to search : ");
    scanf("%c", &ch);
    pos = search(word, start, len - 1, ch);
    if (pos == -1)
        printf("sorry! we didn't found it!");
    else
        printf("yes!we found it at %d position", pos + 1);

    return 0;
}

int search(char know[], int start, int highest, char want)
{
    if (know[start] == want)
        return start;
    else if (know[highest] == want)
        return highest;
    else if (start > highest)
        return -1;

    return search(know, start + 1, highest - 1, want);
}
\\

#include <stdio.h>
#include <string.h>
#define size 100
int search(char know[], int start, int highest, char want);
int main()
{
  int len, pos, start = 0, i, j;
    char a[size], ch, temp;
	    printf("Please Enter a string : ");
	    gets(a);
	    len = strlen(a);
 	    printf("Please Enter which charecter you want to search : ");
	    scanf("%c", &ch);

      for (i = 0; i < strlen(a); i++)
    {
	        for (j = i + 1; j < strlen(a); j++)
	        {
	            if (a[j] >= 65 && a[j] <= 90)
	            {
               if (a[j + 1] >= 65 && a[j + 1] <= 90)
	              {
                    if (a[j] > a[j + 1])
	                    {
                       temp = a[j];
                        a[j] = a[j + 1];
	                        a[j + 1] = temp;
	                    }
	                }
	            }
	
	            // this is for comparing small letter

	            if (a[j] >= 97 && a[j] <= 122)
	            {
	                if (a[j + 1] >= 97 && a[j + 1] <= 122)
               {
	                    if (a[j] > a[j + 1])
                    {
                       temp = a[j];
	                        a[j] = a[j + 1];
	                        a[j + 1] = temp;
	                    }
	                }
           }
	        }
	    }
	    int high = len - 1;
	
	    pos = search(a, start, high, ch);
	    if (pos == -1)
	        printf("sorry! we didn't found it!");
	    else
	        printf("yes!we found it at %d position", pos + 1);
	    return 0;
	}
	int search(char know[], int start, int highest, char want)
	{
	
	    int mid = (start + highest) / 2;
	    if (start > highest)
	    {
        return -1;
    }
	    else if (know[mid] == want)
	        return mid;
   else if (know[mid] < want)
	        start = mid - 1;
	    else
	        highest = mid + 1;
	
	    return search(know, start + 1, highest - 1, want);78.
  }

