# GSM-ESP-JAVA-Controlando-Rele

Esse projeto foi basicamente um estudo meu generalizado para controlar portas do ESP (Wemos D1 no meu caso) à partir de SMS. Para isso foram utilizados os componentes à baixo.

## ESP

No meu caso eu utilizei o Wemos D1, que é uma placa que utiliza o ESP. Basicamente o ESP é um microcontrolador para automatizar e utilizar IoT, ele se conecta na internet e permite ser um servidor ou cliente de chamadas HTTP, dentre outras coisas.

![image](https://github.com/RFHamster/GSM-ESP-JAVA-Controlando-Rele/assets/71076681/f4a4cf5a-80d5-48a5-9e95-93b80fa170fc)

#### Fotos Wemos D1

![image](https://github.com/RFHamster/GSM-ESP-JAVA-Controlando-Rele/assets/71076681/53cdeda9-7e37-42f6-bedf-d6664908f736)


## GSM

No meu caso eu utilizer o Sim 800L em um teste e o Sim 900A em outro. Mas basicamente o módulo GSM é utilizado para comunicação via dados GSM/GPRS, necessita de um chip de operadora de telefonia móvel para comunicação, o módulo pode ter suas ações controladas por diversos tipos de microcontroladores, como o Arduino por exemplo. Para fazer a comunicação a gente utiliza chamadas AT.

## O Projeto

Tá agora nós sabemos o que são os componentes e a ideia geral do Projeto. Basicamente esse repositório mostra alguns estudos que eu fiz para aprender a mexer com o ESP (Wemos D1) e o GSM (Sim 800l) e um código final que será explicado agora.

### Primeira Etapa (Servidor Java)

Basicamente a primeira parte desse projeto é um servidor em Java que funciona como um banco de dados e poderia funcionar como backend para algum front-end que iria consultá-lo. Ele armazena as requisições SMS feitas para o Wemos D1, guardando a data, mensagem da requisição e o usuário.

### Segunda Etapa

Agora é o que realmente interessa, como o código funciona? Basicamente ele abre um servidor no ESP para conseguir fazer as requisições (POST) para o servidor Java (salvar as consultas) e uma comunicação serial para receber e enviar comandos para o GSM. No nosso caso estamos controlando apenas uma porta de um relé, que poderia ser uma forma de desligar um carro roubado por SMS (por exemplo), mas poderia também ser um alarme ou qualquer outra coisa. O código recebe as repostas/SMS do módulo GSM e consegue controlar a porta se utilizar a senha correta. No nosso caso "led on" liga o nosso relé e "led off" desliga nosso relé, mas poderia ser qualquer uma senha que definirmos.
