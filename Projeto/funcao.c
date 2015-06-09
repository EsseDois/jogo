#include "projeto.h"

void DrawPentagrama(){
    int espessura = 2;
    al_draw_line(15, height/2 - 56, width-15, height/2 - 56, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 - 28, width-15, height/2 - 28, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2, width-15, height/2, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 + 28, width-15, height/2 + 28, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 + 56, width-15, height/2 + 56, al_map_rgb(0,0,0), espessura);

}
