#include <stdio.h>

//1.uloha
/*
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return ((double)stick_length * (double)human_weight / ((double)human_weight + (double)car_weight));
}
*/
//2.uloha
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
        return (pack_price/(pieces_count*rolls_count)*100);
}

int main(){
    //1.uloha
    /*
    int a,b,c;
    printf("Zadaj dlzku tyce:\n");
    scanf("%d",&a);
    printf("Zadaj vahu cloveka:\n");
    scanf("%d",&b);
    printf("Zadaj vahu auta:\n");
    scanf("%d",&c);

    printf("%.2f",lift_a_car(a,b,c));
    */
   /////////////////////////////////////////////
   //2.uloha
    int rc,pc;
    float pp;
    printf("Zadajte cenu za balenie:\n");
    scanf("%f",&pp);
    printf("Zadajte pocet kotucov:\n");
    scanf("%d",&rc);
    printf("Pocet utrzkov v kotuci:\n");
    scanf("%d",&pc);
    printf("Jednotkova cena je: %.2f",unit_price(pp,rc,pc));
}