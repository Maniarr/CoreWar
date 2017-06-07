/*
** parser.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Tue Jun  6 08:47:49 2017 MARZI Nicolas
** Last update Tue Jun  6 08:47:49 2017 MARZI Nicolas
*/

#include "op.h"

#ifndef __PARSER_H__
#define __PARSER_H__

typedef unsigned char byte;

typedef struct param_s
{
    char    *label;
    int     value;
    byte    type;
} param_t;


typedef struct instruction_s instruction_t;
struct  instruction_s
{
    byte                    opcode;
    byte                    nb_args;
    param_t                 args[MAX_ARGS_NUMBER];
    instruction_t    *next;
};


typedef struct label_s label_t;
struct  label_s
{
    char     *name;
    byte     position;
    label_t  *next;
};

typedef struct  script_s
{
    label_t         *label;
    instruction_t   *instruction;
    header_t        header;
}               script_t;

int is_label(char *line);
int is_command(char *line);
int is_comment(char *line);
int is_instruction(char *line);
int is_null(char *line);

int is_param_register(char *line);
int is_param_dir(char *line);
int is_param_indir(char *line);
int is_param_valid(char *arg);

char *get_string(char *buffer);
void init_buffer(char *buffer, int size);
void escape_str(char *string);
int array_len(char **array);
char **split_str(char *line, char delimiter);

int set_command(char *line, script_t *script);
int set_label(char *line, script_t *script);
int set_instruction(char *line, script_t *script);

#endif