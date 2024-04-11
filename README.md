# Projeto Sistemas Embarcados - Biblioteca

## Integrantes

- Luís Henrique Lima Santos
- Lucas Bivar Fonseca Tavares
- João Victor Negreiros da Silva
- Lucas Alves Fidelis Araújo
- Lohan Yrvine Oliveira Pinheiro

## Documento do projeto:
[Link para o docs](https://docs.google.com/document/d/1QsI6OhLF0TfYbNzVzPUM2ZsxLW7arz3QbxE7xBPYGtU/edit)

## TODO

**Obs**: Lembrem-se que não podemos de forma NENHUMA implementar coisas em arduino, tudo deve ser um arquivo .C

Firmware:
- [ ] Estruturar projeto no wokwi
  > No momento não temos o sensor, então o ideal seria estrutar o projeto em ambos os wokwi, para que seja possível realizar testes a partir da referência obtida
- [ ] Atualizar repositório do gihub com novos códigos de leitura de dados
- [x] Definir as structs
  - [ ] Salvar dados nos strutcs. Qual dado deve ser salvo no ImuData e no quaternion? Ângulo de Euler é um dado já vindo quaternion?
  - [ ] Salvar dados nos structs correspondentes
  - [ ] Testar se salvar os dados no struct funciona (wokwi)
  - [x] Salvar dados do giroscópio
  - [x] Salvar dados do acelerômetro
- [x] Pesquisar o cálculo do ângulo de Euler
  - [ ] Implementar função que calcula ângulo de Euler
- [x] Pesquisar o cálculo do quartenion
  - [ ] Implementar função de cálculo do quaternion
- [x] Pesquisar e testar o MPU6050 no Wokwi ([Documentação](https://docs.wokwi.com/parts/wokwi-mpu6050))
- [x] Adicionar as interfaces obrigatórias nos componentes

Documentações:
- [ ] Testar o [Kicad](https://www.kicad.org/)
  > Segundo o professor, o esquemático elétrico vai conter apenas o módulo de controle da ESP32 + o sensor MPU6050 + os componentes elétricos utilizadas para entregar ambos.
- [ ] Criar documentação de bibliotecas utilizadas

## Para entregar
- [ ] Firmware contendo um exemplo de utilização da biblioteca.
- [ ] Máquina de estado  do firmware.
- [ ] Documentação da biblioteca desenvolvida
- [ ] Esquemático do hardware.
- [x] Diagrama de bloco para o protótipo do hardware

<!-- https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf  -->
<!-- https://github.com/nkolban/esp32-snippets/blob/d95258eb6c7a8ec6cd537a80cc2b79aa6435aab3/hardware/accelerometers/mpu6050.c -->
<!-- https://wokwi.com/projects/394646687238411265 -->
