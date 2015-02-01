// -----------------------------------
// CSCI 340 - Operating Systems I
// Spring 2015 (Tony Leclerc, Brent Munsell)
// utils.c implementation file
// Homework Assignment 1
//
// -----------------------------------

// ----------------------------------------------
// These are the only libraries that can be
// used. Under no circumstances can additional
// libraries be included

#include <stdio.h>	// IO functions
#include <stdlib.h> 	// atof function
#include <math.h>	// math functions
#include "utils.h"	// your own functions

// Now you put your implementation of the function prototypes here...
int read( char* file_name,v_struct* p_vec_array){



    char s[256];

    int i;

    double r;

    double theta;

    int count;



    FILE* fp;

    fp=fopen(file_name,"r");

    if(fp == NULL){

        printf("Error reading file: %s",file_name);

        count = -1;

    }

    else {

        while (fgets(s, 256, fp) != NULL) {

            if (s[0] != '\n') {


                i = 0;

                while (s[i] != ',' && s[i] != '\0') {


                    i++;

                    if (s[i] == ',') {
                        s[i] = '\0';
                    }

                }
                r = atof(s);

                theta = atof(s + i + 1);


                p_vec_array[count].r = r;

                p_vec_array[count].theta = theta;


                count++;
            }
        }

    }



    return count;



}

double x_component( v_struct* p_vector ){

    double thetaR;

    double xcomp;

    thetaR= p_vector->theta * (PI/180);

    xcomp =p_vector->r *cos(thetaR);

    return xcomp;


}

double y_component( v_struct* p_vector ){

    double thetaR;

    double ycomp;

    thetaR= p_vector->theta * (PI/180);

    ycomp =p_vector->r *sin(thetaR);

    return ycomp;


}

