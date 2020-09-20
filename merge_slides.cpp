#include <iostream>
#include <string>
using namespace std;



/*
   find best merge cost in range and return best cost value
   when caculate cost, by diving problem into two subproblems, we can find optimal cost
 */
int merge_slide(int **cost , int ** index ,int * input, int length) 
{
    
    int end, sum , min, tmp;
    // cost[i][i] is 0
    for( int i = 0 ; i < length;i++)
    {
        cost[i][i] = 0;
    }

   
    for(int i = 2 ; i <= length ;i++)  // when  caculate cost[start][end] , i ls end-start +1 (length) 
    {
        for(int j = 0 ; j <= length -i; j++) // when caculate cost[start][end] , j is start 
        { 
            sum =0;
            end =  j + i -1; // index of end of range 
           
            // find sum of input[start]~ input[end]   
            for(int k = j ; k <= end ; k++) 
            {
                sum = sum +input[k];
            }

            // find best cost in range j~end  
            for(int k = j ; k < end; k++ ) // k is index of spliting the cost problem into two subproblems 
            {
               tmp = cost[j][k] + cost[k+1][end] + sum; // cost : two subproblem's cost + sum of range
               if((k == j) || (min> tmp)) //find smallest cost in range
               {
                   min = tmp;
                   index[j][end] = k; // store split index which cause smallest cost
               }
            }
            cost[j][end] = min; // store smallest cost 
        }
    }
    return cost[0][length-1]; // return best total cost
}

//print order of sum in recursive way
void print_order(int **index, int * input, int start, int end)
{
    if(end-start+1 <= 1) // when problem size is 1 , print number
    {
        cout<<input[start];
        return;
    }
    // when merge two subproblem, print ( )
    cout<<"(";
    print_order(index,input,start,index[start][end]);
    cout<<","; //separate two subproblem
    print_order(index,input,index[start][end]+1,end);
    cout<<")";

}

// to distinguish this string has wrong character or is empty input
int check_wrong(string str)
{
    if((str[0] == ' ') || (str[0] == '\t')) // when first character is blank ->empty input or wrong format
    {
        cout<<"first input is blank or this is empty input"<<endl;
        return 1; // this string is wrong input
    }


    for(int i = 0; i< str.length(); i++)
    {
        if( ((str[i] < 48) || (str[i] > 57)) && (str[i] != ' ') && (str[i] != '\t')) // when str [i] is not number or blank
        {
            cout<<"including not number input"<<endl;
            return 1;// this string is wrong input
        }
    }
    return 0; // this string is right input
}


int main(void)
{
    string str;// get input in string format
    int **cost_array; //  store each range cost to remember subproblem cost so don't need to caculate it again
    int **index_array; //  record best index to split two subproblem which is 
    int *input_array; // store input numbers in integer type 
    int input_size; // store how many input numbers exist 
    int count;

    while(1)
    {

        //initialize values
        input_size = 0;
        count = 0;

        getline(cin,str);  // get input
        if(check_wrong(str)||(str.length()==0)) // when input has wrong format or is empty input
        {
            break; // terminate program
        }
  
        //check input numbers count
        for(int i = 0 ; i < str.length() ; i ++)
        {  
            if(str[i] == ' '|| str[i] == '\t') //check count through blank between numbers 
            {             
                 if( (i+1 < str.length()) && (str[i+1] >= 48) && (str[i+1]<=57))//when this blank split numbers count  
                 {
                    count = count +1;
                 }
            }
        }
      
        input_size = ++count; // include last number in counting
        

        //dynamic allocation for arrays
        input_array = new int[input_size];
        cost_array = new int*[input_size];
        index_array = new int*[input_size];
        for(int i = 0 ; i < input_size; i++)
        {
            cost_array[i] =  new int[input_size];
            index_array[i] = new int[input_size];
        }

        //initialize arrays
        for(int i = 0; i < input_size;i++)
        {
            for(int j = 0 ; j < input_size ; j++)
            {
                cost_array[i][j] = -1;
                index_array[i][j] = -1;
            }
        }
        for(int i = 0 ; i < input_size ; i++)
        {
           input_array[i] = 0;
        }
        
        // convert string into integer array
        count = 0;
        for(int i = 0 ; i < str.length(); i++)
        {
            if((str[i] != ' ') && (str[i] != '\t')) //when str[i] is number
            {
                  input_array[count] = 10 * input_array[count] + (str[i] - 48);  //convert ascii code into integer value until meet blank character
                  if((i+1 < str.length()) &&( (str[i+1]==' ') || (str[i+1]=='\t') )) //when next character is blank, increase input_array index
                  {
                      count = count +1;
                  }
            }
        }
        cout <<merge_slide(cost_array,index_array,input_array,input_size)<<" "; // print best cost of sum
        if(input_size >1)
        {
            print_order(index_array,input_array,0,input_size-1);// print best order of sum
        }
        cout<<endl; // change line
       //deallocate memory 
        for(int i = 0 ; i< input_size; i++)
        {
            delete[] index_array[i];
            delete[] cost_array[i];
        }
        delete[] input_array;
        delete[] cost_array;
        delete[] index_array;
       
    }
    return 0;
}
