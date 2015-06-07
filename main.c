/******************************************************************

                [Insira o nome do Jogo Aqui]
                            por
                Sophia Klein e Sidarta Correa

******************************************************************/

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


const int width = 1024;
const int height = 480;
enum telas {TITULO, MENU, SOBRE, INSTRUCOES, JOGAR, SOL1, FA1, SOL2, FA2, PAUSA, FIM};
int state = TITULO;
int prev_state = NULL;

void DrawPentagrama();

struct Notas
{
    int cx;
    int cy;
    int raio;

} nota;

int main(void)
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *font48, *font24;
    bool quit = false;
    bool redraw = true;

    //INICIALIZAÇÕES
    if(!al_init())
        return -1;
    display = al_create_display(width, height);
    if(!display)
        return -1;
    timer = al_create_timer(1.0/60);
    if(!timer)
        return -1;
    event_queue = al_create_event_queue();
    if(!event_queue)
        return -1;
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_mouse();

    //LISTA DOS POSSIVEIS EVENTOS
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    //CARREGA
    font48 = al_load_font("casale.ttf", 48, 0);
    font24 = al_load_font("casale.ttf", 24, 0);
    //PREPARA
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);
    al_hide_mouse_cursor(display);


//LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(!quit)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            quit = true;
        }

        switch(state)
        {
        case TITULO:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 1)
                    state = MENU;
            }
            break;

        case MENU:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 1)
                    prev_state = state;
                    state = JOGAR;
            }
            break;

        case SOBRE:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 2)
                    prev_state = state;
                    state = MENU;
            }
            break;

        case INSTRUCOES:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 2)
                    prev_state = state;
                    state = MENU;
            }
            break;

        case JOGAR:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 1)
                    prev_state = state;
                    state = SOL2;
            }
            break;

        case SOL1:
            break;

        case FA1:
            break;

        case SOL2:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 2)
                    prev_state = state;
                    state = PAUSA;

            }
            break;

        case FA2:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {

            }
            break;

        case PAUSA:
            if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                nota.cx = ev.mouse.x;
                nota.cy = ev.mouse.y;
            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(ev.mouse.button & 2)
                    state = prev_state;
            }
            break;

        case FIM:
            break;

        } //switch da parte lógica

//PARTE GRAFICA/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(redraw)
        {
            ALLEGRO_COLOR color_bg1 = al_map_rgb(100,149,227); //azul escuro
            ALLEGRO_COLOR color_bg2 = al_map_rgb(138,174,234); //azul claro
            ALLEGRO_COLOR color_black = al_map_rgb(0,0,0);
            ALLEGRO_COLOR color_white = al_map_rgb(255,255,255);

            switch(state)
            {
            case TITULO:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                al_draw_text(font48, color_white, width/2, height/8, ALLEGRO_ALIGN_CENTER, "TITULO");
                al_draw_text(font24, color_white, width/2, height*3/4, ALLEGRO_ALIGN_CENTER, "CLIQUE PARA CONTINUAR");
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case MENU:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                DrawPentagrama();
                al_draw_text(font48, color_white, width/2, height/8, ALLEGRO_ALIGN_CENTER, "TITULO");
                al_draw_text(font24, color_white, width/8, (height/2)-84, ALLEGRO_ALIGN_LEFT, "Jogar");
                al_draw_text(font24, color_white, width/8, (height/2)-28, ALLEGRO_ALIGN_LEFT, "Instrucoes");
                al_draw_text(font24, color_white, width/8, (height/2)+28, ALLEGRO_ALIGN_LEFT, "Sobre");
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case SOBRE:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                al_draw_text(font48, color_white, width/2, height/8, ALLEGRO_ALIGN_CENTER, "[Escrever sobre o jogo aqui]");
                al_flip_display();
                break;

            case INSTRUCOES:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                al_draw_text(font48, color_white, width/2, height/8, ALLEGRO_ALIGN_CENTER, "[Explicar como jogar]");
                al_flip_display();
                break;

            case JOGAR:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                DrawPentagrama();
                if(nota.cx < width/2){
                    al_draw_text(font24, color_white, width/4, (height/2)-56, ALLEGRO_ALIGN_LEFT, "Modo 1");
                    al_draw_text(font24, color_white, width/4, (height/2), ALLEGRO_ALIGN_LEFT, "Modo 2");
                }
                else{
                    al_draw_text(font24, color_white, width*3/4, (height/2)-56, ALLEGRO_ALIGN_LEFT, "Modo 1");
                    al_draw_text(font24, color_white, width*3/4, (height/2), ALLEGRO_ALIGN_LEFT, "Modo 2");
                }
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case SOL1:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                DrawPentagrama();
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case FA1:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                DrawPentagrama();
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case SOL2:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                DrawPentagrama();
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case FA2:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                DrawPentagrama();
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case PAUSA:
                al_clear_to_color(color_bg1);
                al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
                al_draw_text(font48, color_white, width/2, height/2, ALLEGRO_ALIGN_CENTER, "Jogo Pausado");
                al_draw_circle(nota.cx, nota.cy, 14, color_black, 2);
                al_flip_display();
                break;

            case FIM:
                break;
            } //switch gráfico
        } //if gráfico

    } //while da porra toda

    al_destroy_display(display);
    return 0;
}

void DrawPentagrama(){
    int espessura = 2;
    al_draw_line(15, height/2, width-15, height/2, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 - 28, width-15, height/2 - 28, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 - 56, width-15, height/2 - 56, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 + 28, width-15, height/2 + 28, al_map_rgb(0,0,0), espessura);
    al_draw_line(15, height/2 + 56, width-15, height/2 + 56, al_map_rgb(0,0,0), espessura);
}
