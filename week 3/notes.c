/*

-----    Lecture     -----

REVIEW: 

    cs50 Tools      help50; style50; check50; printf; debug50; ddb (duck debugger)


ALGORITHMS:

    when designing algorithms, there are different factors to consider:
        memory usage
        runtime
        complexity / ease to code + debugging 
        time to code vs time to run


    running time = how long an algorithm takes to run

        big O notation 
            how does the MAXIMUM runtime increase as the size of the problem increases

            e.g. if runtime increases linearly with size of problem, this is denoted as O(n)
            e.g. if runtime does not change with size of problem, this is denoted as O(1)

            e.g. O(n^2); O(n log n); O(n); O(log n); O(1); (from longest to fastest)
        
        Ω (omega) notation 
            how does the MINIMUM runtime increase as the size of the problem increases

            same as big O notation except for minimum       e.g. Ω(n)

        Θ (theta) notation 
            if an alg has the same MINIMUM and MAXIMUM runtime, they can be collectively denoted using Θ
                e.g. Θ(n); means that the algorithm has O(n) and Ω(n)


    searching algorithms - check if an element is in an array/list

        linear search = go through each element one by one until found or finished
            
            -----   -----   -----   -----   -----
                pseudocode:
                    for i from 0 to n-1 {
                        if number is behind i'th door {
                            return true
                        }
                    }
                    return false
            -----   -----   -----   -----   -----
            
            runtime:    O(n)    Ω(1)


        binary search = only possible if elements are sorted

            uses recursion

            -----   -----   -----   -----   -----
                pseudocode:
                    sort doors

                    if there are no doors 
                        return false                        (base case)
                    go to middle door
                        if number is behind middle door
                            return true
                        else if number < middle door 
                            search left half                (recursive step)
                        else if number > middle door 
                            search right half               (recursive step)
                    }
            -----   -----   -----   -----   -----
                        
            runtime:    O(log n)    Ω(1)

    
    
    sorting algorithms - sort an array numerically / alphabetically

        selection sort
            1. go through each element to find the smallest number
            2. swap with number in the first spot
            3. go through each element to find the second smallest
            4. swap with number in the second spot
            etc. etc.
            
            -----   -----   -----   -----   -----
                pseudocode:                    
                    for i from 0 to n-1 {

                        var lowest;

                        for q from i to n-1 {
                            if item is less than lowest {
                                lowest becomes item;
                            }
                        }

                        swap lowest with i'th item
                    }
            -----   -----   -----   -----   -----
            
            runtime:    O(n^2)    Ω(n^2)
        

        bubble sort
            1. loop through the array, compare two adjacent numbers and swap if necessary
            2. repeat until there is an iteration where there are no swaps

            make sure you use a swap-counter variable 
            
            -----   -----   -----   -----   -----
                pseudocode:  
                    repeat n-1 times:            
                        for i from 0 to n-2 {
                            if i'th and i+1'th elements out of order {
                                swap them
                            }
                        }
                        if no swaps
                            quit (because its sorted)
            -----   -----   -----   -----   -----
            
            runtime:    O(n^2)    Ω(n)

                bubble sort is asymptotically equivalent to selection sort as both are O(n^2)

        merge sort
            1. use recursion lol
            
            -----   -----   -----   -----   -----
                pseudocode:
                    if one number:
                        quit                            (base case)                    
                    sort left half of numbers           (recursive step)
                    sort right half of numbers          (recursive step)
                    merge halves                        
            -----   -----   -----   -----   -----
            
            runtime:    O(n log n)    Ω(n log n)

                merge sort has better runtime, but uses more memory (twice as much)





recursion - where a function calls itself
    base case - a line of code that terminates recursion





function in string.h
    strcmp(string1, string2)
        if string1 == string2; strcmp returns 0
        if string1 before string2 "alphabetically" (actually the ASCII values); strcmp returns a number < 0
        if string1 after string2 "alphabetically" (actually the ASCII values); strcmp returns a number > 0




STRUCTURES:
    you can essentially create your own data type (like an object / dictionary / class)

    code:    
        typedef struct
        {
            datatype variableName;
            datatype variableName;
        }
        structureName;

*/




/// ----- CODE -----

//#include <stdio.h>


// creating a datatype called person, with two "fields": name and number


int main(void) 
{
    typedef struct
    {
        string name;
        string number;
    }
    person;

    person person1;
    person1.name = "Brian";
    person1.number = "0429471294";
}











// LAB 3
/*

REAL TIMES
                    reversed5000.txt            sorted5000.txt              reversed10000.txt       reversed50000.txt
sort1     bubble    0.111s                      0.016s                      0.399s                  15.288s
sort2               0.011s                      0.015s                      0.038s                  04.376s
sort3               0.038s                      0.055s                      0.287s                  08.549s

*/
