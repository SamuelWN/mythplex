/* postprocess.c
   (c) 2016 Mike Todaro, not for commercial use, all rights reserved
   No warranties or gurantees, express or implied, are given by the author.
   Use this software at your own risk! Any effect(s) it has on your systems
   or anything else are not my responsibility!


   postprocess.c is a replacement for my BASH script that takes MythTV
   recordings and cleans them up and presents them to Plex for later
   viewing.
*/

#include <stdlib>
#include <stdio>
#include <glib/glib.h>
#include <string>

int main(int argc, char *argv[])
{
   /* command line variables */
   char[] chanid;
   char[] starttime;

   GError error;

   /* config file */
   GKeyFile *config_file; = g_key_file_new();

   /* configuration dictionary */
   GHashTable* config = g_hash_table_new(g_str_hash, g_str_equal);

   if (!(g_key_file_load_from_file(config_file, "./postprocess.conf", G_KEY_FILE_NONE, error))
   {
     fprintf(stderr, "Cannot load config file! Exiting.", __FILE__);
     exit(1);
   }

   /* Get the list of keys. */
   char keys[][] = g_key_file_get_keys(config_file, "General", NULL, error);

   /* Insert config file values into our config hash table. */
   for (int k = 0; k < sizeof(keys); k++)
   {
     g_hash_table_insert(config, keys[k], g_key_file_get_string(config_file, "General", keys[k], error));
   }

   g_key_file_free(config_file); /* Release the keyfile and move on. */

   

   return 0;
}