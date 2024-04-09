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

Firmware:
- [x] Adicionar as interfaces obrigatórias nos componentes
- [x] Definir as structs
  - [ ] Salvar dados nos strutcs %\to% qual dado deve ser salvo no ImuData e no quaternion?
  - [ ] Salvar dados do giroscópio
- [ ] Pesquisar o cálculo do ângulo de Euler
- [ ] Pesquisar o cálculo do quartenion
- [x] Pesquisar e testar o MPU6050 no Wokwi ([Documentação](https://docs.wokwi.com/parts/wokwi-mpu6050))

Documentações:
- [ ] Testar o [Kicad](https://www.kicad.org/)
  > Segundo o professor, o esquemático elétrico vai conter apenas o módulo de controle da ESP32 + o sensor MPU6050 + os componentes elétricos utilizadas para entregar ambos.

## Para entregar
- [ ] Firmware contendo um exemplo de utilização da biblioteca.
- [ ] Máquina de estado  do firmware.
- [ ] Documentação da biblioteca desenvolvida
- [ ] Diagrama de bloco para o protótipo do hardware
- [ ] Esquemático do hardware.

## Links úteis
- https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf 
<!-- - https://github.com/nkolban/esp32-snippets/blob/d95258eb6c7a8ec6cd537a80cc2b79aa6435aab3/hardware/accelerometers/mpu6050.c -->
<!-- https://wokwi.com/projects/394646687238411265 -->
