// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

/**
 * @file		Languages.cpp
 * @brief	All translations source file
 * All variables related to language translations
*/
#include <string>

#include "Languages.hpp"




std::string en_string[] = { "Menu", "Start", "Quit", "Settings", "English", "Italian", "Language", "Back", "Reset settings" }; /**< Array of strings to contain all English string translations */
std::string it_strings[] = { "Men\158", "Inizia", "Esci", "Impostazioni", "Inglese", "Italiano", "Lingua", "Indietro", "Impostazioni predefinite" }; /**< Array of strings to contain all Italian string translations */

std::string en_status[] = { "Bye Bye!", "That's not an option", "Select a language", "Select an option", "Enter a command" }; /**< Array of strings to contain all English status messages translations */
std::string it_status[] = { "Ciao ciao!", "Quella opzione non è disponibile", "Seleziona una lingua", "Seleziona un'opzione", "Inserire un comando" }; /**< Array of strings to contain all Italian status messages translations */

std::string en_story[] = {}; /**< Array of strings to contain all English story translations */
std::string it_story[] = {}; /**< Array of strings to contain all Italian story translations */


std::string* Languages::strings[] = { en_string, it_strings };
std::string* Languages::status[] = { en_status, it_status};
std::string* Languages::story[] = { en_story, it_story};
