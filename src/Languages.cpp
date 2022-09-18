// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

#include <string>

#include "Languages.hpp"



/**
 * @brief Array of strings to contain all English string translations
*/
std::string en_string[] = {
	"Menu",
	"Start",
	"Quit",
	"Settings",
	"English",
	"Italian",
	"Language",
	"Back",
	"Reset settings",
	"Bye bye",
	"West",
	"North",
	"East",
	"South",
	"Look around",
	"Climb",
	"Fig",
	"Palm",
	"Drink",
	"Eat",
	"Proceed",
	"Boat",
	"Fight",
	"Befriend",
	"Run",
	"Enter",
	"Ignore",
	"Trust",
	"Play again"
};

/**
 * @brief Array of strings to contain all Italian string translations
*/
std::string it_strings[] = {
	"Menù",
	"Inizia",
	"Esci",
	"Impostazioni",
	"Inglese",
	"Italiano",
	"Lingua",
	"Indietro",
	"Impostazioni predefinite",
	"Ciao ciao",
	"Ovest",
	"Nord",
	"Est",
	"Sud",
	"Guardati attorno",
	"Arrampicati",
	"Fico",
	"Palma",
	"Bevi",
	"Mangia",
	"Procedi",
	"Barca",
	"Combatti",
	"Fai amicizia",
	"Scappa",
	"Entra",
	"Ignora",
	"Fidati",
	"Gioca ancora"
};



/**
 * @brief Array of strings to contain all English status messages translations
*/
std::string en_status[] = {
	"Bye Bye!",
	"That's not an option",
	"Select a language",
	"Select an option",
	"Enter a command",
	"Press enter to continue",
	"The end"
};

/**
 * @brief Array of strings to contain all Italian status messages translations
*/
std::string it_status[] = {
	"Ciao ciao!",
	"Quella opzione non è disponibile",
	"Seleziona una lingua",
	"Seleziona un'opzione",
	"Inserire un comando",
	"Premere invio per continuare",
	"Fine"
};



/**
 * @brief Array of strings to contain all English story translations
*/
std::string en_story[] = {
	"You're a Muriqui and have just escaped the Sao Paulo Zoo.\nYou have the jungle ahead of you and freedom is calling.\nYou are searching for your peers.",
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
	"You consider straying from the way, but aside from the little space you're staying and the straight way you see no opening.",
	"You see the little space you're staying in, the way in front of you and a strong tree beside you.\nYou hear a strong buzz coming from that tree.",
	"You consider following the stream, but you see that the river ends in a cliff.",
	"You look at the stream, you see your reflection in it and see, on top of the water, a wooden construction tied to your side of the river.",
	"You get close to the water when suddenly, before you can even react, a big, scaly creatures bites you head and drags you in the water.\nYou are dead.",
	"You hop on the wooden construction and start rowing with your hands until you reach the other side of the stream.\nYou see some tall hairless monkeys with brightly colored bodies and strange black squares in their hands.\nThey look at you: some frightened, some amused.",
	"You ate a couple of the fruits on the tree; you are sated.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
	"You proceed through the branches.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
	"You see the fruits on the tree and an interminable series of branches.",
	"You try to reach for one of the fruits, but suddenly a giant slithering creature attacks you, but you manage to throw the fruit at him and run.\nYou are hungry and wounded.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
	"You try to reach for one of the fruits, but suddenly a giant slithering creature attacks you.\nHe coils around you crushing you bones, you feel a growing pressure then black.\nYou're dead.",
	"You head to the top of the tree and you proceed jumping from leaf to leaf.\nAfter some time, you climb down the top of the tree to rest.\nYou find a strange, hairless monkey with a strange metal cylinder in his hands.\nIt noticed you, it looks threatening.",
	"You see the fruits under the tree's leaves, you also see how these leaves can support your weight.\nYou notice nothing else, despite this, you feel threatened",
	"You proceed following the road ahead of you, you hear a grunt. You don't notice it at first, but a jaguar is waiting you,\nwatching.",
	"You scream, show your teeth, and charge the big cat.\nIt bounces on you and start mauling you.\nYou are dead.",
	"You try to run away, but the predator is faster and manages to reach you.\nIt bounces on you and start mauling you.\nYou are dead.",
	"You swiftly reach the tree trunk, the big cat is right behind you.\nYou rapidly climb up the tree, despite its best efforts, the jaguar can't follow you and gives up on preying you.\nYou shake off the scare and proceed to find a series of pyramidal constructions.",
	"You can barely see the predator, but you notice him.\nYou see the road continuing in front of you and a robust tree at running distance.",
	"You climb up the buzzing tree to find a circular, white and wavy thing attached to the trunk.",
	"You take a bite out of the white circle only for the big insects inside it to start stinging you.\nYou run for a while and manage to lose them.\nYou find a series of pyramidal constructions.",
	"You take a bite out of the white circle only for the big insects inside it to start stinging you.\nYou feel weaker and weaker as you proceed and then: black.\nYou are dead.",
	"You ignore the strange object and proceed thorugh the trees.\nYou look down to find a group of pyramidal constructions.",
	"You look at the object more closely and notice big red insects frenetically entering and exiting the strange sphere.\nYou see a way through the branches and hear your stomach rumbling.",
	"You start screaming at them and show your teeth, they scream in terror.\nYou hear a whistle then... dark.\nYou hear familiar noises, smell familiar scents, you open your eyes: you are back where you started: you are at the Sao Paulo Zoo.",
	"You slowly walk towards one of the creatures: he initially flinches, but then he slowly lends his arm towards you. You hop on his shoulder and walk with him and other similar creatures that look at you in awe.\nAfter walking for a lot of time, the creature heads towards a strange metal box.\nMeanwhile you hear a familiar call in the distance.",
	"You scream at him and show your teeth, he points the cylinder at you and then... an explosion, then darkness.\nYou are dead.",
	"You slowly approach the strange creature, initially he points the cylinder at you, but then he takes out a fruit and hands it to you.\nHe signals you to come, reluctant but tired, you hop on his shoulder and eat.\nYou proceed with him: you hear distant voices but the man avoids them.\nAfter a long time walking, you hear a familiar call. You take a last look at the kind giant and follow the call,\nthere they are! Your troop is waiting for you, you have reunited with your kind.",
	"You run from the creature and after a while, you hear strange voices, you follow them and notice other hairless monkeys with nets and cylinders.\nThey immediately notice you, point the cylinder and then...black.\nYou hear familiar noises, smell familiar scents, you open your eyes: you are back where you started: you are at the Sao Paulo Zoo.",
	"You approach the village and enter one of the constructions.",
	"You avoid the strange constructions and after a while, you hear strange voices, you follow them and notice other hairless monkeys with nets and cylinders.\nThey immediately notice you, point the cylinder and then...black.\nYou hear familiar noises, smell familiar scents, you open your eyes: you are back where you started: you are at the Sao Paulo Zoo.",
	"You see some fruits on a surface and hear some voices from outside the construction.",
	"You ignore the sound that was before attracting you and enter the strange box.\nIt starts moving, you're initially scared but after a while, tireness gets the best of you and you fall asleep.\nYou wake up in a strange small place, you start yelling but the creature you trusted gives you food and pets you, you calm down.\nA lot of time has now passed since your journey, you are now used to the strange creature's care and attention, sometimes you still recall and feel that urge to break free, but you are now too accustomed to this new way of living: you are now a pet.",
	"You can't resist the call, you follow it then,\nthere they are! Your troop is waiting for you, you have reunited with your kind.",
	"You eat some of the fruits, one of the voices screams at you and you promptly escape.\nYou hear a familiar call,\nthere they are! Your troop is waiting for you, you have reunited with your kind.",
	"You decide to ignore the food and head out of that weird place.\nAfter a while walking, you hear a familiar call,\nthere they are! Your troop is waiting for you, you have reunited with your kind."
};

/**
 * @brief Array of strings to contain all Italian story translations
*/
std::string it_story[] = {
	"Sei un Muirqui e sei appena scappato dallo Zoo di San Paolo.\nHai la giungla davanti a te e la libertà ti chiama.\nStai cercando i tuoi simili.",
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
	"Consideri di deviare dalla strada davanti a te, ma oltre al piccolo spiazzo in cui ti trovi e la suddetta via, non vedi aperture.",
	"Vedi il piccolo spiazzo dove ti trovi, la strada davanti a te e un grosso albero affianco a te.\nSenti un forte ronzio provenire dall'albero.",
	"Consideri di seguire il corso del fiume, ma presto ti accorgi che il fiume termina a strapiombo.",
	"Guardi il corso d'acqua, ti specchi sulla sua superificie e vedi, sul pelo dell'acqua, una costruzione in legno legata alla tua sponda del fiume.",
	"Ti avvicini all'acqua, ma improvvisamente, prima di poter anche solo reagire, una grossa, squamosa creatura ti morde la testa e ti porta in acqua.\nSei morto.",
	"Salti sulla costruzione di legno e inizi a remare con le braccia finchè non raggiungi l'altra sponda.\nVedi delle scimmie alte e senza peli con corpi di colori sgargianti e strani quadrati neri nelle mani.\nTi guardano: alcuni spaventati, altri divertiti.",
	"Hai mangiato un paio dei frutti sull'albero; sei sazio.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi è accorta della tua presenza, ha l'aria minacciosa.",
	"Procedi attraverso i rami.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi è accorta della tua presenza, ha l'aria minacciosa.",
	"Vedi i frutti sull'albero e una serie interminabile di rami.",
	"Cerchi di arrivare ad uno dei frutti, ma improvvisamente una creatura gigante e strisciante ti attacca, riesci a colpirla con il frutto e scappare.\nSei affamato e ferito.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi è accorta della tua presenza, ha l'aria minacciosa.",
	"Cerchi di arrivare ad uno dei frutti, ma improvvisamente una creatura gigante e stisciante ti attacca.\nSi attorciglia intorno a te rompendoti le ossa, senti una deastante e sempre crescente pressione e poi: buio.\nSei morto.",
	"Ti dirigi in cima all'albero e procedi saltando da foglia a foglia.\nTempo dopo scendi dalla cima per riposarti.\nTi imbatti in una strana, scimmia senza peli con uno strano cilindro di metallo nelle sue mani.\nSi è accorta della tua presenza, ha l'aria minacciosa.",
	"Vedi i frutti sotto le foglie dell'albero, vedi anche che queste foglie riescono a sostenere il tuo peso.\nNon noti nient'altro, nonostante ciò, ti senti in pericolo.",
	"Procedi lungo la via di fronte a te, senti un grugnito. Non te ne accorgi inizialmente, ma un giaguaro ti sta aspettando, ti osserva.",
	"Urli, mostri i denti e carichi il grosso gatto.\nTi salta addosso e inizia ad azzannarti.\nSei morto.",
	"Cerchi di scappare, ma il predatore è più veloce e ti raggiunge.\nTi salta addosso e inizia ad azzannarti.\nSei morto.",
	"Raggiungi rapidamente il tronco dell'albero, il grosso gatto è dietro di te.\nTi arrampichi velocemente sull'albero, nonstante il suo impegno, il giaguaro non riesce a seguirti e abbandona l'idea di cacciarti.\nTi liberi della paura e procedi trovando una serie di costruzioni piramidali.",
	"Riesci a malapena a scorgere il predatore, ma riesci ad individuarlo.\nVedi la strada continuare davanti a te ed un robusto albero a distanza di corsa.",
	"Ti arrampichi sull'albero ronzante e trovi una cosa tonda, bianca e ondulata attaccata al tronco.",
	"Addenti il cerchio bianco e vieni subito punto dai grandi insetti che ci vivevano dentro.\nScappi per un po' e riesci a seminarli.\nTrovi una serie di costruzioni piramidali.",
	"Addenti il cerchio bianco e vieni subito punto dai grandi insetti che ci vivevano dentro.\nDiventi sempre più debole mentre procedi e poi: buio.\nSei morto.",
	"Ignori lo strano oggetto e procedi tra gli alberi.\nGuardi in basso e trovi un gruppo di costruzioni a piramide.",
	"Guardi più attentamente all'oggetto e noti grandi e rossi insetti che entrano ed escono freneticamente dalla strana sfera.\nVedi una via tra i rami e senti il tuo stomaco brontolare.",
	"Urli contro di loro e mostri i denti; terrorizzati, urlano a loro volta.\nSenti un fischio e poi... nero.\nSenti suoni familiari, senti odori familiari, apri gli occhi: sei tornato al punto di partenza: sei allo zoo di San Paolo.",
	"Lentamente ti avvicini alla creatura la quale inizialmente tentenna, ma poi, lentamente, tende il suo braccio verso di te. Salti sulla sua spalla e cammini con lui e delle altre creature simili a lui che ti guardano meravigliate.\nDopo aver camminato per molto tempo, la creatura si dirige verso una strana scatola metallica.\nNel frattempo, senti un richiamo familiare nella distanza.",
	"Inizi ad urlare e mostrare i denti, il gigante spaventato punta verso di te il cilindro e poi... un'esplosione, poi nero.\nSei morto.",
	"Lentamente ti avvicini alla strana creatura, inizialmente punta il cilindro verso di te, ma poi prende un frutto e te lo passa.\nTi fa cenno di raggiungerlo, esitante ma stanco, salti sulla sua spalla e mangi.\nProcedi con lui: senti distanti voci, ma l'uomo le evita.\nDopo una lunga camminata, senti un richiamo familiare. Guardi un'ultima volta al gigante gentile e insegui il richiamo,\neccoli! Il tuo branco ti attende, ti sei riunito con i tuoi simili.",
	"Scappi dalla creatura e dopo un bel po' di strada, senti strane voci, le segui e noti altre scimmie senza peli con reti e cilindri.\nSi accorgono di te immediatamente, puntano a te i cilindri e poi...nero.\nSenti suoni familiari, senti odori familiari, apri gli occhi: sei tornato al punto di partenza: sei allo zoo di San Paolo.",
	"Ti avvicini al villaggio ed entri una delle costruzioni.",
	"Eviti le strane costruzioni e dopo un bel po' di strada, senti strane voci, le segui e noti altre scimmie senza peli con reti e cilindri.\nSi accorgono di te immediatamente, puntano a te i cilindri e poi...nero.\nSenti suoni familiari, senti odori familiari, apri gli occhi: sei tornato al punto di partenza: sei allo zoo di San Paolo.",
	"Vedi della frutta su una superficie e senti delle voci provenienti da fuori la costruzione.",
	"Ignori il suono che ti stava prima attraendo ed entri nella scatola di metallo.\nInizia a muoversi, inizialmente ti spaventi ma dopo un po', la stanchezza ha la meglio e ti addormenti.\nTi svegli in uno strano piccolo posto, inizi ad urlare e la creatura di cui ti sei fidato ti porge del cibo e ti accarezza, riesci a calmarti.\nMolto tempo è ormai passato dal tuo viaggio e ti sei abituato alle attenzioni e cure della strana creatura. A volte ricordi e senti la voglia di libertà, ma ormai sei troppo abituato al tuo nuovo stile di vita per tornare: sei diventato un animale domestico",
	"Non resci ad ignorare la chiamata, la segui e poi,\neccoli! Il tuo branco ti attende, ti sei riunito con i tuoi simili.",
	"Mangi un po' della frutta sulla superficie e una delle voci ti urla contro e prontamente scappi.\nSenti un richiamo familiare,\neccoli! Il tuo branco ti attende, ti sei riunito con i tuoi simili.",
	"Decidi di ignorare il cibo e andartene da quello strano posto.\nDopo un po' di camminata, senti un richiamo familiare,\neccoli! Il tuo branco ti attende, ti sei riunito con i tuoi simili."
};



/**
 * @brief Array of strings to contain all English title translations
*/
std::string en_titles[] = {
	"Language",
	"Settings",
	"Main menu",
	"Prologue",
	"Crossroad",
	"Forest",
	"River",
	"Fig",
	"Palm",
	"Square",
	"Tourists",
	"Hunter",
	"Jaguar",
	"Village",
	"Hornet Nest",
	"Good Ending",
	"Bad Ending",
	"Neutral Ending",
	"The End"
};

/**
 * Array of strings to contain all English title translations
*/
std::string it_titles[] = {
	"Lingua",
	"Impostazioni",
	"Menù principale",
	"Prologo",
	"Bivio",
	"Foresta",
	"Fiume",
	"Fico",
	"Palma",
	"Piazza",
	"Turisti",
	"Cacciatore",
	"Giaguaro",
	"Villaggio",
	"Nido di Calabroni",
	"Good Ending",
	"Bad Ending",
	"Neutral Ending",
	"Fine"
};

std::string* Languages::strings[] = { en_string, it_strings };
std::string* Languages::status[] = { en_status, it_status };
std::string* Languages::story[] = { en_story, it_story };
std::string* Languages::titles[] = { en_titles, it_titles };
