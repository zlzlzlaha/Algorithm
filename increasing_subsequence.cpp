#include <iostream>
#include <string>

using namespace std;


/*
   function to caculate LIS, store each previous element's index in LIS and return index of end of LIS
   check previous element's LIS length and this element is smaller than now index elements, then find longest LIS in this index
*/
int find_sequence(int * length , int * index, string input) // length is array to store LIS length in each index. index is array to store previous element's index in LIS 
{
    int max;
    int max_length_index = 0; // index of end of LIS 

    //find LIS length in specific index
    for(int i = 0 ; i < input.length(); i++)
    {
        max = length[i]; // initial max value

        //check previous element's LIS length
        for(int j = 0 ; j < i; j++)
        {
            if((input[j] < input[i]) && (length[j]+1 > max)) //when there is smaller element and it's LIS length+1 is maximum value 
            {
                    max = length[j]+1;
                    index[i] = j; // store previous element's index in LIS
            }
        }
        length[i] = max; // length of LIS in specific index


        //find specific index which has longest length
        if(length[i]> length[max_length_index]) 
        {
            max_length_index = i;
        }

    }
    return max_length_index; //return input array index which has longetst subsequence
}

// find a element which is LIS from the back, then print element from the front
void print_sequence(int *length, int *index, string input,int print_index)
{
    if(print_index != index[print_index]) //when this not elemenet of first subsequence , because first element's index array value is it's index 
    {
        print_sequence(length,index,input,index[print_index]);
    }
    cout<<input[print_index]; // print character

}

// return this string is empty or not
int check_empty(string str)
{
    for(int i = 0 ; i < str.length(); i++)
    {
        if((str[i]!=' ')&&(str[i]!='\t')) // when exist a no blank character 
        {
            return 0; // this string is not empty
        }
    }
    return 1; //this string is empty
}

int main(void)
{
    string input; // get input in string 
    int input_size;
    int *length; // array to store the length of longest subsequence problem form 0 to specific index
    int *index; // array to store previous subsequence's element index
    int print_index;//string index to be printed 
     while(1)
    {

        //initialize input size to 0
        input_size = 0;
        getline(cin,input); //get input from stdin

        //when input is empty,  end program
        if(check_empty(input)) 
        {
            break;
        }


        //when there is  blank  middle of input, only get inputs before blank
        for(int i = 0 ; i < input.length() ; i++)
        {
            if(( input[i]==' ') || (input[i]=='\t'))
            {
                break;
            }
            input_size ++; //check new input size
        }
        
        input.resize(input_size); //resize input string to eliminate after ' '


        // dynamic allocation for arrays
        length  = new int[input_size];
        index = new int[input_size];
        // initialize  array
        for(int i = 0 ; i < input_size ;i++)
        {
            length[i] = 1; //inital length value is 1
            index[i] = i; // inital index is it's index
        }
       
        print_index =find_sequence(length,index,input); //caculate longest increasing subsequence and return input index which has longest increasing subsequence
        print_sequence(length,index,input,print_index); //print longest increasing subsequence
        cout<<endl; // change line

        //deallocate memory
        delete[] length;
        delete[] index;
    }
    return 0;
}
