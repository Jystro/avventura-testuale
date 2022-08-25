// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "Languages.hpp"
#include <string>


std::string en_string[] = { "Menu", "Start", "Quit", "Settings", "English", "Italian", "Language", "Back", "Reset settings" };
std::string it_strings[] = { "Men\158", "Inizia", "Esci", "Impostazioni", "Inglese", "Italiano", "Lingua", "Indietro", "Impostazioni predefinite" };

std::string en_status[] = { "Bye Bye!", "That's not an option", "Select a language", "Select an option", "Enter a command" };
std::string it_status[] = { "Ciao ciao!", "Quella opzione non è disponibile", "Seleziona una lingua", "Seleziona un'opzione", "Inserire un comando" };

std::string en_story[] = { "You're a Muriqui and have just escaped the Sao Paulo Zoo.\nYou have the jungle ahead of you and freedom is calling.\nYou are searching for your peers.",
                           "You are faced with a crossroad: you can either go left, straight or right.\nYou are facing North.",
                           "You decide to take the left route.\nYou enter deeper into the jungle, you see an always denser group of trees.",
                           "You decide to head straight.\nYou face a jaguar who's looking hungry and straight at you.",
                           "You decide to take the right route.\nYou run and run and arrive at a crystalline clear stream of water. You feel thirsty.",
                           "You consider heading back, but you feel you don't really want that.",
                           "You see the jungle: tall green trees cover you from a burning yellow sun.\nYou hear the quiet sounds of moving and living nature.\nSomehow, you distinguish three paths from the wilderness.",
                           };
std::string it_story[] = { "Sei un Muirqui e sei appena scappato dallo Zoo di San Paolo.\nHai la giungla davanti a te e la libertà ti chiama.\nStai cercando i tuoi simili.",
                           "Ti trovi di fronte ad un bivio: puoi andare a sinistra, dritto o alla tua destra.\nSei rivolto a Nord.",
                           "Decidi di imboccare la strada a sinistra.\nTi addentri sempre pi\158 nella foresta, vedi un gruppo sempre più fitto di alberi.",
                           "Decidi di procedere dritto.\nTi imbatti in un giaguaro ha l'aria affamata e guarda dritto verso di te.",
                           "Decidi di imboccare la strada a destra.\nCorri e corri e arrivi ad un corso d'acqua cristallino. Ti senti assetato.",
                           "Valuti l'opzione di tornare indietro, ma senti di non volerlo davvero.",
                           "Vedi la giungla: alti e verdi alberi ti coprono da uno scottante giallo sole.\nSenti il silenzioso suono della natura vivente ed in moto.\nIn qualche modo riesci a distinguere tre percorsi dalla selva."};
std::string* Languages::strings[] = { en_string, it_strings };
std::string* Languages::status[] = { en_status, it_status};
std::string* Languages::story[] = { en_story, it_story};
