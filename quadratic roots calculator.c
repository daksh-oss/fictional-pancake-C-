

#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,D,r1,r2;

    printf("enter the coeffecient of x^2:\n");
    scanf("%f", &a);
    printf("enter the coeffecient of x:\n");
    scanf("%f", &b);
    printf("enter the constant:\n");
    scanf("%f", &c);
    printf("your quadratic equation is:%2.fx^2+%2.fx+%2.f\n\n",a,b,c);
    D=pow(b,2)-4*a*c;
    if(D<0){
        printf("roots will be imaginary\n");
        return 0;
    }
    
        else if(D==0){
        printf("roots are real and equal\n");
        
        }
        
          else if (D>0){
        printf("roots are real and distinct\n");
          }
    
    
    r1= (-b+sqrt(D))/ (2*a);
    r2= (-b-sqrt(D))/ (2*a);
    printf("the two roots for the given equation are : %f,%f\n\n", r1,r2);
        
        
    
    return 0;
    
}
