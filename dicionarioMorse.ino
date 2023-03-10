// Define as portas que serão usadas para o LED e para o Serial
const int LED_VERDE = 6;
const int LED_VERMELHO = 7;
const int SERIAL_BAUD_RATE = 9600;

// Define as letras do alfabeto e seus códigos em Morse
const char* LETRAS[] = {
    ".-",    //A
    "-...",  //B
    "-.-.",  //C
    "-..",   //D
    ".",     //E
    "..-.",  //F
    "--.",   //G
    "....",  //H
    "..",    //I
    ".---",  //J
    "-.-",   //K
    ".-..",  //L
    "--",    //M
    "-.",    //N
    "---",   //O
    ".--.",  //P
    "--.-",  //Q
    ".-.",   //R
    "...",   //S
    "-",     //T
    "..-",   //U
    "...-",  //V
    ".--",   //W
    "-..-",  //X
    "-.--",  //Y
    "--.."   //Z
};

// Função para converter uma letra em código Morse
String convertToMorse(char c) {

    // Converte para letra maiúscula
    c = toupper(c);

    // Retorna vazio para caracteres inválidos
    if (c < 'A' || c > 'Z') return "";
    
    // Calcula o índice do array
    int index = c - 'A';
    return LETRAS[index];
}

void setup() {
  
    // Define a porta do LED como saída
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);

    // Inicializa o Serial com a taxa de baud rate definida
    Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
    if (Serial.available()) {

        // Lê uma letra do Serial
        char c = Serial.read();
        
        // Converte a letra para maiúsculo
        c = toupper(c);
        
        // Converte a letra em código Morse
        String morse = convertToMorse(c);
        
        // Envia a letra em seu valor ASCII correspondente
        Serial.write(c);
        Serial.print(": ");

        // Imprime o código Morse no Serial
        Serial.println(morse);

        //imprime letra por letra nos leds
        for (int i = 0; i < morse.length(); i++) {
          
            if (morse[i] == '.') { // Faz o LED piscar para o ponto
              
                digitalWrite(LED_VERDE, HIGH);
                delay(200);
                digitalWrite(LED_VERDE, LOW);
                delay(200);
                
            } else if (morse[i] == '-') { // Faz o LED piscar para o traço
              
                digitalWrite(LED_VERDE, HIGH);
                delay(600);
                digitalWrite(LED_VERDE, LOW);
                delay(200);
                
            }
        }

        //aqui entra o fim da letra, então acende o led vermelho
        digitalWrite(LED_VERMELHO, HIGH);
        delay(1000);
        digitalWrite(LED_VERMELHO, LOW);
    }
}
