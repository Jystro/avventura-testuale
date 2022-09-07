// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "Languages.hpp"
#include <string>


std::string en_string[] = { "Menu", "Start", "Quit", "Settings", "English", "Italian", "Language", "Back", "Reset settings" }; /**< Array of strings to contain all English string translations */
std::string it_strings[] = { "Men\158", "Inizia", "Esci", "Impostazioni", "Inglese", "Italiano", "Lingua", "Indietro", "Impostazioni predefinite" }; /**< Array of strings to contain all Italian string translations */

std::string en_status[] = { "Bye Bye!", "That's not an option", "Select a language", "Select an option", "Enter a command" }; /**< Array of strings to contain all English status messages translations */
std::string it_status[] = { "Ciao ciao!", "Quella opzione non è disponibile", "Seleziona una lingua", "Seleziona un'opzione", "Inserire un comando" }; /**< Array of strings to contain all Italian status messages translations */

/**
 * Array of strings to contain all English story translations
*/
std::string en_story[] = { "You're a Muriqui and have just escaped the Sao Paulo Zoo.\nYou have the jungle ahead of you and freedom is calling.\nYou are searching for your peers.",
                           "You are faced with a crossroad: you can either go left, straight or right.\nYou are facing North.",
                           "You decide to take the left route.\nYou are met with two thick groups of trees.",
                           "You decide to head straight.\nYou enter deeper into the jungle, after a while you stop in the middle of the road.",
                           "You decide to take the right route.\nYou run and run and arrive at a crystalline clear stream of water. You feel thirsty.",
                           "You consider heading back, but you feel you don't really want that.",
                           "You see the jungle: tall green trees cover you from a burning yellow sun.\nYou hear the quiet sounds of moving and living nature.\nSomehow, you distinguish three paths from the wilderness.",
                           "You try to find a way through the trees, but their trunks and roots won't let you go through.",
                           "You look at the trees:\none group has purple and green fruits hanging from its branches;\nthe other group has round, brown and hairy fruits under its leaves.",
                           "You choose to climb a tree, you ponder on which of the trees will you go up to (1/2).",
                           "You choose to climb one of the purple-colored fruit trees.\nYou feel hungry.",
                           "You choose to climb one of the brown-colored fruit trees.\nYou feel hungry.",
                           "You ate a couple of the fruits on the tree; you are sated.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
                           "You proceed through the branches.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
                           "You see the fruits on the tree and an interminable series of branches.",
                           "You try to reach for one of the fruits, but suddendly a giant slithering creature attacks you, but you manage to throw the fruit at him and run.\nYou are hungry and wounded.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
                           "You head to the top of the tree and you proceed jumping from leaf to leaf.\nAfter some time, you climb down the top of the tree to rest.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
                           "You see the fruits under the tree's leaves, you also see how these leaves can support your weight.\nYou notice nothing else, despite this, you feel threatened",
                           "You slowly approach the strange creature, initially he points the cylinder at you, but then he takes out a fruit and hands it to you.\nHe signals you to come, reluctant but tired, you hop on his shoulder and eat.\nYou proceed with him: you hear distant voices but the man avoids them.\nAfter a long time walking, you hear a familiar call. You take a last look at the kind giant and follow the call,\nthere they are! Your troop is waiting for you, you have reunited with your kind.",
                           "You run from the creature and after a while, you hear strange voices, you follow them and notice other hairless monkeys with nets and cylinders.\nThey immediately notice you, point the cylinder and then...black.\nYou hear familiar noises, smell familiar scents, you open your eyes: you are back where you started: you are at the Sao Paulo Zoo."
                           };
/**
 * Array of strings to contain all Italian story translations
*/
std::string it_story[] = { "Sei un Muirqui e sei appena scappato dallo Zoo di San Paolo.\nHai la giungla davanti a te e la libertà ti chiama.\nStai cercando i tuoi simili.",
                           "Ti trovi di fronte ad un bivio: puoi andare a sinistra, dritto o alla tua destra.\nSei rivolto a Nord.",
                           "Decidi di imboccare la strada a sinistra.\nTi imbatti in due folti gruppi di alberi.",
                           "Decidi di procedere dritto.\nEntri più nel profondo della giungla, dopo una lunga camminata ti fermi sulla strada.",
                           "Decidi di imboccare la strada a destra.\nCorri e corri e arrivi ad un corso d'acqua cristallino. Ti senti assetato.",
                           "Valuti l'opzione di tornare indietro, ma senti di non volerlo davvero.",
                           "Vedi la giungla: alti e verdi alberi ti coprono da uno scottante giallo sole.\nSenti il silenzioso suono della natura vivente ed in moto.\nIn qualche modo riesci a distinguere tre percorsi dalla selva.",
                           "Cerchi di passare attraverso gli alberi, ma i loro tronchi e le loro radici non ti permettono di passare.",
                           "Guardi gli alberi:\nun gruppo ha frutti viola e verdi che pendono dai suoi rami;\nl'altro gruppo ha frutti tondi, marroni e pelosi sotto le sue foglie.",
                           "Scegli di arrampicarti su un albero, rifletti su quale degli alberi scalerai (1/2).",
                           "Scegli di arrampicarti su uno degli alberi dai frutti viola.\nSei affamato.",
                           "Scegli di arrampicarti su uno degli alberi dal frutto marrone.\nSei affamato.",
                           "Hai mangiato un paio dei frutti sull'albero; sei sazio.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi \138 accorta della tua presenza, ha l'aria minacciosa.",
                           "Procedi attraverso i rami.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi \138 accorta della tua presenza, ha l'aria minacciosa.",
                           "Vedi i frutti sull'albero e una serie interminabile di rami.",
                           "Cerchi di arrivare ad uno dei frutti, ma improvvisamente una creatura gigante e strisciante ti attacca, riesci a colpirla con il frutto e scappare.\nSei affamato e ferito.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi \138 accorta della tua presenza, ha l'aria minacciosa.",
                           "Ti dirigi in cima all'albero e procedi saltando da foglia a foglia.\nTempo dopo scendi dalla cima per riposarti.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi \138 accorta della tua presenza, ha l'aria minacciosa.",
                           "Vedi i frutti sotto le foglie dell'albero, vedi anche che queste foglie riescono a sostenere il tuo peso.\nNon noti nient'altro, nonostante ci\149, ti senti in pericolo.",
                           "Lentamente ti avvicini alla strana creatura, inizialmente punta il cilindro verso di te, ma poi prende un frutto e te lo passa.\nTi fa cenno di raggiungerlo, esitante ma stanco, salti sulla sua spalla e mangi.\nProcedi con lui: senti distanti voci, ma l'uomo le evita.\nDopo una lunga camminata, senti un richiamo familiare. Guardi un'ultima volta al gigante gentile e insegui il richiamo,\neccoli! Il tuo branco ti attende, ti sei riunito con i tuoi simili.",
                           "Scappi dalla creatura a dopo un bel po' di strada, senti strane voci, le segui e noti altre scimmie senza peli con reti e cilindri.\nSi accorgono di te immediatamente, puntano a te i cilindri e poi...nero.\nSenti suoni familiari, senti odori familiari, apri gli occhi: sei tornato al punto di partenza: sei allo zoo di San Paolo."
                           };

std::string* Languages::strings[] = { en_string, it_strings };
std::string* Languages::status[] = { en_status, it_status};
std::string* Languages::story[] = { en_story, it_story};
