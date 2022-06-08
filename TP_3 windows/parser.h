//todo lo relacionado a la lectura y escritura de archivos
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListPassenger);

int parser_guardarBinario(FILE* pFile , LinkedList* pArrayListPassenger);
