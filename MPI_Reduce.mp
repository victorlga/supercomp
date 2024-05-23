Claro! Aqui está uma tabela fácil de ler com as operações predefinidas disponíveis para a função `MPI_Reduce` no MPI:

| **Operação**    | **Descrição**                                                                 | **Exemplo de Uso**                                                                                   |
|-----------------|-------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| `MPI_SUM`       | Soma de todos os elementos.                                                   | `[1, 2, 3, 4]` -> `10`                                                                               |
| `MPI_PROD`      | Produto de todos os elementos.                                                | `[1, 2, 3, 4]` -> `24`                                                                               |
| `MPI_MAX`       | Máximo valor entre os elementos.                                              | `[1, 2, 3, 4]` -> `4`                                                                                |
| `MPI_MIN`       | Mínimo valor entre os elementos.                                              | `[1, 2, 3, 4]` -> `1`                                                                                |
| `MPI_MAXLOC`    | Combina o valor máximo e sua localização (índice do processo).                | `[1, 3, 2]` -> `{3, 1}` (valor 3, processo 1)                                                        |
| `MPI_MINLOC`    | Combina o valor mínimo e sua localização (índice do processo).                | `[1, 3, 2]` -> `{1, 0}` (valor 1, processo 0)                                                        |
| `MPI_BAND`      | AND bit a bit entre todos os elementos.                                       | `[1, 3, 7]` (binário `01`, `11`, `111`) -> `1` (binário `01`)                                        |
| `MPI_BOR`       | OR bit a bit entre todos os elementos.                                        | `[1, 3, 7]` (binário `01`, `11`, `111`) -> `7` (binário `111`)                                       |
| `MPI_BXOR`      | XOR bit a bit entre todos os elementos.                                       | `[1, 3, 7]` (binário `01`, `11`, `111`) -> `5` (binário `101`)                                       |
| `MPI_LAND`      | AND lógico entre todos os elementos.                                          | `[true, false, true]` -> `false`                                                                     |
| `MPI_LOR`       | OR lógico entre todos os elementos.                                           | `[true, false, true]` -> `true`                                                                      |
| `MPI_LXOR`      | XOR lógico entre todos os elementos.                                          | `[true, false, true]` -> `false`                                                                     |

### Explicação das Operações

- **`MPI_SUM`**: Soma dos valores.
- **`MPI_PROD`**: Produto dos valores.
- **`MPI_MAX`**: Valor máximo.
- **`MPI_MIN`**: Valor mínimo.
- **`MPI_MAXLOC`**: Valor máximo e o rank do processo que possui esse valor.
- **`MPI_MINLOC`**: Valor mínimo e o rank do processo que possui esse valor.
- **`MPI_BAND`**: AND bit a bit.
- **`MPI_BOR`**: OR bit a bit.
- **`MPI_BXOR`**: XOR bit a bit.
- **`MPI_LAND`**: AND lógico.
- **`MPI_LOR`**: OR lógico.
- **`MPI_LXOR`**: XOR lógico.