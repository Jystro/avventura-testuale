// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "Languages.hpp"
#include <string>


std::string en_string[] = { "Menu", "Start", "Quit", "Settings", "English", "Italian", "Language", "Back", "Reset settings" };
std::string it_strings[] = { "Men\158", "Inizia", "Esci", "Impostazioni", "Inglese", "Italiano", "Lingua", "Indietro", "Impostazioni predefinite" };

std::string en_status[] = { "Bye Bye!", "That's not an option", "Select a language", "Select an option", "Enter a command" };
std::string it_status[] = { "Ciao ciao!", "Quella opzione non è disponibile", "Seleziona una lingua", "Seleziona un'opzione", "Inserire un comando" };

std::string* Languages::strings[] = { en_string, it_strings };
std::string* Languages::status[] = { en_status, it_status};
