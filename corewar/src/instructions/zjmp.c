/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#include "game.h"
#include "instructions.h"

void zjmp(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int jmp;

    if (cursor->registers[0] == 0)
        return;
    jmp = read_byte_to_int(memory, cursor->position + 1, IND_SIZE) % IDX_MOD;
    cursor->position = (cursor->position + jmp) % IDX_MOD;
    bypass_programs(programs, nb_programs);
}
