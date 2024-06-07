/*AG-Brinquedos

QUIZ EDUCATIVO SOBRE OS OCEANOS

Nome: Guilherme Araujo de Carvalho
RM: 558926
Nome: Augusto Douglas Nogueira de Mendonça
RM: 558371
*/

#define tempo 10
#include <LiquidCrystal.h>  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 


// Criação das Variaveis Globais -------------------------------------
 int frequencia = 0;
 int porta;
 String botao;
 int estado = 1;
 int ponto = 0;
 boolean flag = false;
 int aux = 0; 
 int Acertou = 3;
 int Errou = 2;
 int Buzzer = 10; 

//--------------------------------------------------------------------

void setup()   {  
  lcd.begin(16, 2); 
  pinMode (Acertou, OUTPUT);
  pinMode (Errou, OUTPUT);
  pinMode (Buzzer, OUTPUT);
}  

//--------------------------------------------------------------------

void loop()  { 

  switch (estado) {

    case 1: 
            ponto = 0;
            
            lcd.clear();
            lcd.home();  
            lcd.print("  BEM VINDO AO"); 
            lcd.setCursor(0,1);  
            lcd.print("   JOGO QUIZ!"); 
            
            delay (2000);
            
            lcd.clear();
            lcd.home();  
            lcd.print("  CRIADO POR :"); 
            lcd.setCursor(0,1);  
            lcd.print(" AG-Brinquedos"); 
            
            delay (2000);

            lcd.clear();
            lcd.home();  
            lcd.print(" USE AS TECLAS"); 
            lcd.setCursor(0,1);  
            lcd.print("   UP e DOWN"); 

            delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("PARA ESCOLHER A"); 
            lcd.setCursor(0,1);  
            lcd.print("RESPOSTA CORRETA"); 

            delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("E A TECLA *LEFT*"); 
            lcd.setCursor(0,1);  
            lcd.print("PARA RETORNAR");
    
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("TECLE SELECT P/"); 
            lcd.setCursor(0,1);  
            lcd.print("  CONFIRMAR"); 

            delay (3000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("   QUIZ SOBRE "); 
            lcd.setCursor(0,1);  
            lcd.print("    OCEANOS!"); 

            delay (3000);

            estado = 2;

            break;
            
    case 2: 
            lcd.clear();
            lcd.home();  
            lcd.print("PRESSIONE SELECT "); 
            lcd.setCursor(0,1);  
            lcd.print("   PARA  JOGAR"); 

            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Select"){
              estado = 110;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }
    
    		delay (200);

            break;
    case 4: 
            lcd.clear();
            lcd.home();  
            lcd.print("Total: "); 
            lcd.setCursor(7,0);  
            lcd.print(ponto); 
            lcd.setCursor(9,0);  
            lcd.print("Pontos");

            if (ponto >=7){
              lcd.setCursor(0,1);  
              lcd.print(" Foi muito bem!! ");
            }

            if (ponto <=2){
              lcd.setCursor(0,1);  
              lcd.print(" Não foi dessa vez '-' ");
            }
    
            if ((ponto > 3) and (ponto < 6)){
              lcd.setCursor(0,1);  
              lcd.print(" Tente novamente! ");
            }

            delay (3000);
            estado = 1;
            ponto = 0;

            

            break;
            
    case 110: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 1:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual e o maior oceano do mundo?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <17; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Oceano Atlantico ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Oceano Pacifico ()");
    		
    		delay (200);
    		estado = 111;
    		aux =0; 
    
    		break;
    
    case 111:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = true;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 120;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 120;	
                  delay (3000);
  
 
                  
                  
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 120;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 110;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;

  
    
    case 120:
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 2:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual e a profundidade media dos oceanos?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <24; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("1000 metros ()"); 
            lcd.setCursor(0,1);  
            lcd.print("4000 metros ()");
    		
    		delay (200);
    		estado = 121;
    		aux =0; 
    
    		break;
    
    case 121:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = true;
              aux++;
              
            }
   
       else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 130;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 130;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 130;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 120;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 130:
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 3:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual e a cor do oceano vista do espaco?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <24; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Verde ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Azul ()");
    		
    		delay (200);
    		estado = 131;
    		aux =0; 
    
    		break;
    
    case 131:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = true;
              aux++;
              
            }
    
    	else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 140;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 140;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                 lcd.print("Poxa, era facil!");
                
				estado = 140;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 130;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 140: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 4:"); 
            lcd.setCursor(0,1);  
            lcd.print("Como o plastico afeta a vida marinha?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <22; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Melhora ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Prejudica ()");
    		
    		delay (200);
    		estado = 141;
    		aux =0; 
    
    		break;
    
    case 141:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = true;
              aux++;
              
            }
    
    	else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 150;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  estado = 150;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 150;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 140;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
                
    case 150: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 5:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual oceano faz fronteira com o Brasil?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <24; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Atlantico ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Indico ()");
    		
    		delay (200);
    		estado = 151;
    		aux =0; 
    
    		break;
    
    case 151:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 160;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 160;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 160;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 150;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
            
    case 160: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 6:"); 
            lcd.setCursor(0,1);  
            lcd.print("O nosso planeta e mais composto de?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <19; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Agua ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Terra ()");
    		
    		delay (200);
    		estado = 161;
    		aux =0; 
    
    		break;
    
    case 161:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                 digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
                  
                  ponto++;
                  estado = 170;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 170;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 170;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 160;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 170: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 7:"); 
            lcd.setCursor(0,1);  
            lcd.print("O que e uma mare vermelha?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <11; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Desastre Natural ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Mare alta ()");
    		
    		delay (200);
    		estado = 171;
    		aux =0; 
    
    		break;
    
    case 171:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
                  
                  ponto++;
                  estado = 180;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 180;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 180;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 170;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 180: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 8:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual e o maior animal do mundo?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <15; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Baleia-azul ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Elefante ()");
    		
    		delay (200);
    		estado = 181;
    		aux =0; 
    
    		break;
    
    case 181:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
                  
                  ponto++;
                  estado = 190;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 190;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 190;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 180;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 190: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 9:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual lixo mais encontrado nos oceanos?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <24; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Vidro ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Plastico ()");
    		
    		delay (200);
    		estado = 191;
    		aux =0; 
    
    		break;
    
    case 191:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = true;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                 digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 200;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 200;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 200;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 190;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 200: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 10:"); 
            lcd.setCursor(0,1);  
            lcd.print("Por que e importante reciclar?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <15; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("Proteger os oceanos ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Economizar dinheiro ()");
    		
    		delay (200);
    		estado = 210;
    		aux =0; 
    
    		break;
    
    case 210:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("Opcao A ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Opcao B (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Acertou !!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens!!!");
                 digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 4;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("Errou       :("); 
                  lcd.setCursor(0,1);
                  lcd.print("Tente a proxima!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  estado = 4;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Pulou Mesmo?!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Poxa, era facil!");
                
				estado = 4;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 200;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
  }

}

void lcd_Shield () {

   botao = "vazio";

   if (porta < 100) {  
      botao = "Direita";  
   }  
   else if (porta < 200) {  
      botao = "Cima";  
   }  
   else if (porta < 400){  
      botao = "Baixo";  
   }  
   else if (porta < 600){  
      botao = "Esquerda";  
   }  
   else if (porta < 800){  
      botao = "Select";  
   } 
}

void tecla_Error(){
  lcd.clear();
  lcd.home();
  lcd.print (" Tecla Errada!! ");
  delay (1000); 
}