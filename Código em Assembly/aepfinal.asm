.data
	#MENSAGENS
	bemvindo:                .asciiz "         Bem-vindo ao App do AI QUI DILIÇA"
	pula:                    .asciiz "\n"
	telacadastral:           .asciiz "                Tela de Cadastro"
	pnome:  	         .asciiz "Insira o seu nome completo: "
	pcidade:                 .asciiz "Insira a sua Cidade: "
	puf:                     .asciiz "UF: "
	pdatadenascimento:       .asciiz "Data de Nascimento(ex.: 10/02/1988): "
	pemail:		         .asciiz "Insira o seu e-mail: "
	psenha:                  .asciiz "Insira a sua Senha: "
	cadastroef:              .asciiz "  ** Cadastro efetuado com sucesso! **"
	
	imprimenome:  	         .asciiz "              Nome: "
	imprimecidade:           .asciiz "            Cidade: "
	imprimeuf:               .asciiz "                UF: "
	imprimedatadenascimento: .asciiz "Data de Nascimento: "
	imprimeemail:		 .asciiz "            E-mail: "
	imprimesenha:            .asciiz "             Senha: "
	

	 
	#Variaveis
	nome:              .space 30
	cidade:            .space 30
	uf:                .space 3
	datanascimento:    .space 12
	email:             .space 50
	senha:             .space 16
.text 
	li $v0,4
	la $a0, bemvindo
	syscall
	
	li $v0,4
	la $a0,pula
	syscall
	
	jal cadastro
	jal printinfo
	jal saida
	
cadastro:
	li $v0,4
	la $a0, telacadastral
	syscall
	
	li $v0,4
	la $a0,pula
	syscall
	
	li $v0,4
	la $a0,pula
	syscall
	#--------------- NOME -----------------
	li $v0,4
	la $a0, pnome
	syscall
	
	li $v0,8
	la $a0, nome
	la $a1, 30
	syscall
	
	move $s0,$a0
	
	
	#--------------- CIDADE -----------------
	li $v0,4
	la $a0, pcidade
	syscall
	
	li $v0,8
	la $a0, cidade
	la $a1, 30
	syscall
	
	move $s1,$a0
	
	
	#--------------- ESTADO -----------------
	
	li $v0,4
	la $a0, puf
	syscall
	
	li $v0,8
	la $a0, uf
	la $a1, 3
	syscall
	
	move $s2,$a0
	
	li $v0,4
	la $a0,pula
	syscall
	
	#--------------- DATA DE NASCIMENTO -----------------
	
	li $v0,4
	la $a0, pdatadenascimento
	syscall
	
	li $v0,8
	la $a0, datanascimento
	la $a1, 12
	syscall
	
	move $s3,$a0
	
	
	#--------------- EMAIL -----------------
	
	li $v0,4
	la $a0, pemail
	syscall
	
	li $v0,8
	la $a0, email
	la $a1, 50
	syscall
	
	move $s4,$a0
	
	
	#--------------- SENHA -----------------
	
	li $v0,4
	la $a0, psenha
	syscall
	
	li $v0,8
	la $a0, senha
	la $a1, 10
	syscall
	
	move $s5,$a0
	
	li $v0,4
	la $a0,pula
	syscall
	
	li $v0,4
	la $a0,cadastroef
	syscall
	li $v0,4
	la $a0,pula
	syscall
	li $v0,4
	la $a0,pula
	syscall
	
	jr $ra
	
printinfo:
#------------------------------- IMPRIME NOME ---------------------------------------------- 
	li $v0,4
	la $a0,imprimenome
	syscall
	
	li $v0,4
	la $a0, ($s0)
	syscall
	
	
#------------------------------- IMPRIME CIDADE -----------------------------------------------
	li $v0,4
	la $a0,imprimecidade
	syscall
	
	li $v0,4
	la $a0, ($s1)
	syscall
	
	
#------------------------------- IMPRIME ESTADO ----------------------------------------------	li $v0,4
	la $a0,imprimeuf
	syscall
	
	li $v0,4
	la $a0, ($s2)
	syscall
	
	li $v0,4
	la $a0,pula
	syscall
#------------------------------- IMPRIME DATA DE NASCIMENTO ----------------------------------------------
	li $v0,4
	la $a0,imprimedatadenascimento
	syscall
	
	li $v0,4
	la $a0, ($s3)
	syscall
	

#------------------------------- IMPRIME E-MAIL ----------------------------------------------	
	li $v0,4
	la $a0,imprimeemail
	syscall
	
	li $v0,4
	la $a0, ($s4)
	syscall
	
	
#------------------------------- IMPRIME SENHA ----------------------------------------------	
	li $v0,4
	la $a0,imprimesenha
	syscall
	
	li $v0,4
	la $a0, ($s5)
	syscall
	
	
	
	jr $ra 
saida:
 	li $v0,10
 	syscall
	
	
