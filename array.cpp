//
//  main.cpp
//  project 4
//
//  Created by Isabelle Hales on 10/30/22.
//  Copyright © 2022 CS31. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

//append value to end of each element of array, return n (n can't be negative)
int appendToAll (string a[], int n, string value) {
    if(n < 0){
        return -1;
    }
    
    for(int i = 0; i < n; i++){
        a[i] += value;
    }
        
    return n;
        
}

//return position of string in array that is equal to target
int lookup (const string a[], int n, string target){
    
    for(int i = 0; i < n; i++){
        if(a[i] == target){
            return i;
        }
    }
    
    return -1;
}

//return position of string in array
int positionOfMax (const string a[], int n) {
    
    string maxString = a[0];
    
        
    for(int i = 0; i < n; i++){
        if(a[i] >= maxString){
            maxString = a[i];
        }
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] == maxString){
            return i;
        }
    }
    
    
    return -1;
}

//eliminate item at position pos, add it to the end. return positiong removed
int rotateLeft (string a[], int n, int pos) {
    a[n-1] = a[pos];
    
    for(int i = pos; i < n - 1; i++){
        a[i] = a[i+1];
    }
    
    return pos;
}

//return number of one or more consecutive identical items
int countRuns (const string a[], int n) {
    int runs = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] != a[i+1]){
            runs++;
        }
    }
    return runs;
}

//reverse order of elements in string a
int flip (string a[], int n){
    
    for(int i = 0; i < n/2; i++){
        string temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    return n;
}

//Return the position of the first corresponding elements of a1 and a2 that are not equal. return whichever value of n1 and n2 is less than or equal to the other.
int differ (const string a1[], int n1, const string a2[], int n2) {
    int maxElem = 0;
    if(n1 <= n2){
        maxElem = n1;
    } else {
        maxElem = n2;
    }
    
    for(int i = 0; i < maxElem; i++){
        if(a1[i] != a2[i]){
            return i;
        }
    }

    if(n1 < n2) {
        return n1;
    } else {
       return n2;
    }
}

//if all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence.
int subsequence (const string a1[], int n1, const string a2[], int n2) {
    
    if(n2 == 0){
        return 0;
    }
    
    for(int i = 0; i < n1; i++){
        if(a1[i] == a2[0]){
            for(int j = 0; j < n2; j++){
                if(a2[j] != a1[i+j]){
                    break;
                } if(j == n2-1 && a2[j] == a1[i+j]){
                    return i;
                }
            }
        }
    }
    return -1;
}

//Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no element of a1 is equal to any element of a2.
int lookupAny (const string a1[], int n1, const string a2[], int n2) {
    
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(a1[i] == a2[j]){
                return i;
            }
        }
    }
    return -1;
}

//rearrange array, any elements with value less than splitter come before other elements
int split (string a[], int n, string splitter){
    
    //reorder array
    for(int i = 0; i < n ; i++){
            if(a[i] >= splitter){
                for(int j = i + 1; j < n; j++){
                    if(a[j] < splitter){
                        swap (a[i], a[j]);
                    }
                }
            }
        }
        
    //return position
    for(int i = 0; i < n ; i++){
        if(a[i] >= splitter){
            return i;
        }
    }
        
    return n;
}

int main() {

    string h[7] = { "rishi", "margaret", "gordon", "tony", "", "john", "liz" };
    assert(lookup(h, 7, "john") == 5);
    assert(lookup(h, 7, "gordon") == 2);
    assert(lookup(h, 2, "gordon") == -1);
    assert(positionOfMax(h, 7) == 3);

    string g[4] = { "rishi", "margaret", "liz", "theresa" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "rishi?" && g[3] == "theresa?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "liz?" && g[3] == "margaret?");

    string e[4] = { "gordon", "tony", "", "john" };
    assert(subsequence(h, 7, e, 4) == 2);

    string d[5] = { "margaret", "margaret", "margaret", "tony", "tony" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "liz", "gordon", "tony" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "tony" && f[2] == "liz");
    
    assert(split(h, 7, "liz") == 3);
    
    cout << "All tests succeeded" << endl;
    
    return 0;
}
