# Funções de Controle
tarefa Frente com numero velocidade = 150{
	Motor("me", velocidade)
	Motor("md", velocidade)
	Motor("me1", velocidade)
	Motor("md1", velocidade)
	#Motor("mc", velocidade)
}

tarefa Direita com numero velocidade = 250{
	Motor("me", velocidade*2)
    Motor("md", 0-(velocidade*2))
	Motor("me1", velocidade*2)
    Motor("md1", 0-(velocidade*2))
	#Motor("mc", velocidade*2)
}

tarefa Esquerda com numero velocidade = 250{
	Motor("me", 0-(velocidade*2))
	Motor("md", velocidade*2)
	Motor("me1", 0-(velocidade*2))
	Motor("md1", velocidade*2)
	#Motor("mc", velocidade*2)
}

tarefa Direita1 com numero velocidade = 250{
	Motor("me", velocidade*2)
    Motor("md", 0-(velocidade*2))
	Motor("me1", velocidade*2)
    Motor("md1", 0-(velocidade*2))
	#Motor("mc", velocidade*2)
}

tarefa Tras com numero velocidade = 500{
	Motor("me", 0-velocidade)
	Motor("md", 0-velocidade)
	Motor("me1", 0-velocidade)
	Motor("md1", 0-velocidade)
	#Motor("mc", 0-velocidade)
}


numero contador = 0
tarefa LedFinal {
	para contador de 1 ate 5 passo 1 farei {
    	LigarLuz("led", 255, 0, 0)
		Esperar(50)
		LigarLuz("led", 0, 255, 0)
		Esperar(50)
		LigarLuz("led", 0, 0, 255)
		Esperar(50)

		}

}


	
		inicio

	    
        #DefinirMotor("mg",500,0-25)
	    #DefinirMotor("mg1",500,0-25)
	    #DefinirMotor("mg2",500,0-25)
		TravarMotor("g1", falso)
		TravarMotor("g1", falso)   
		
		Motor("g1", 300)
		Esperar(2000)
		
		TravarMotor("g1", verdadeiro)
		TravarMotor("g1", verdadeiro)  

		TravarMotor("me", falso) # Destrava o motor da esquerda
    	TravarMotor("md", falso) # Destrava o motor da direita
		TravarMotor("me1", falso)
		TravarMotor("md1", falso)
	
		


		se (Toque("ct") == verdadeiro) entao {
		Tras(250)
		Esperar(500)
       Esquerda(200)
        Esperar(2200)
        Frente(175)
        Esperar(2000)
        Direita(200)
        Esperar(2200)
        Frente(250)
        Esperar(3000)
        Direita(110) 
        Esperar(2200)
        Frente(175)
        Esperar(2500)
        Esquerda(130)
        Esperar(2000)
		}


		
		enquanto (verdadeiro) farei {
		Esperar(2)
		se (Ultra("uc")> 0) entao {
		se( Ultra("uc")< 2 ) entao {
		Esquerda(100)
		Esperar(7000)
		Frente(100)
		Esperar(4000)
		Direita(110)
		Esperar(4000)
		Frente(150)
		Esperar(4000)
		Direita(120) 
		Esperar(4000)
		Frente(120)
		Esquerda(50)
		}}

		


							 # Importate para evitar a quebra do simulador

		senao se (CorVerde("cd") >CorAzul("cd") +20 e CorVerde("ce") >CorAzul("ce") +20) entao {
        LigarLuz("led", 255, 255, 255)
		Direita(300)
		Esperar(2000)}

        senao se(CorVerde("cd") >CorAzul("cd") +20 ou CorVerde("cd1") >CorAzul("cd1") +20) entao {
        LigarLuz("led", 255, 255, 255)
        Frente(100)
        Esperar(1000)
        Direita(300)
        Esperar(2000)
        enquanto(Cor("cd") != "Preto") farei {
        Esperar(100)
        Direita(150)
          }
		Frente(100)
        Esperar(300)

        } senao se(CorVerde("ce") >CorAzul("ce") +20 ou CorVerde("ce1") >CorAzul("ce1") +20) entao {
        LigarLuz("led", 255, 255, 255)
        Frente(200)
        Esperar(1200)
        Esquerda(400)
        Esperar(2000)
        enquanto(Cor("ce") != "Preto") farei { 
        Esperar(100)
        Esquerda(200) 
            }
		Frente(200)
        Esperar(400)
        }

		senao se(CorAzul("ce") >CorVerde("ce") +20 ou CorAzul("ce1") >CorVerde("ce1") +20) entao {
		LigarLuz("led", 255, 0, 255)
		Frente(300)
		Esperar(1000)}



		se((Cor("cd") == "Preto" ou Cor("cd1") == "Preto") e (Cor("ce") == "Branco" ou Cor("ce1") == "Branco")) 				entao {
		LigarLuz("led", 0, 0, 255)
		Direita(150)} 

		senao se((Cor("cd") == "Branco" ou Cor("cd1") == "Branco") e (Cor("ce") == "Preto" ou Cor("ce1") == 					"Preto")) entao {
		LigarLuz("led", 255, 0, 0)
		Esquerda(200)
       	}
	
		
		senao se((CorAzul("cd1") > CorVermelho("cd1") +15 ) ou (CorAzul("ce1") > CorVermelho("ce1") +15 )) entao {
		Frente(350)
		LigarLuz("led", 255,255,255)
		Esperar(2000)

		TravarMotor("g1", falso)
		TravarMotor("g1", falso)   
		
		Motor("g1", 0-270)
		Esperar(1000)
		
		TravarMotor("g1", verdadeiro)
		TravarMotor("g1", verdadeiro) 
 
		} senao { 
		LigarLuz("led", 255, 0, 255)
		Frente(250)	
		}

		se ((Cor("cd1") == "Preto") e (Cor("cd") == "Preto")) entao {
		Frente(100)
		Esperar(1100)
		enquanto(Cor("ce") != "Preto") farei {  
		Esperar(50)
		Direita(200) }


 		se ((Cor("ce1") == "Preto") e (Cor("ce") == "Preto")) entao {
		Frente(100)
		Esperar(1100)
		enquanto(Cor("cd") != "Preto") farei { 
		Esperar(50)
		Esquerda(200) 
        }

		enquanto (Cor("ce") != "Preto") farei {
        Frente(100)
		Esperar(50)
		}

		Esperar(2000)
		enquanto (Cor("cd") != "Preto") farei {
		Esquerda(100)
		}
		
   	}
}
		}
fim