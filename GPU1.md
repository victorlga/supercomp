### Resumo dos Principais Conceitos e Funcionalidades do Thrust

**Iteradores:**
- `thrust::constant_iterator`: Gera valores constantes.
- `thrust::count_if`: Conta elementos que satisfazem uma condição.
- `thrust::replace_if`: Substitui elementos baseados em uma condição.

**Transformações e Reduções:**
- Uso de iteradores para evitar alocação extra de memória.
- Transformações eficientes com operações padrão e customizadas.

### Exemplos de Código

**Exemplo 1: Constante e Sequência**

```cpp
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/fill.h>
#include <thrust/sequence.h>

int main() {
    thrust::device_vector<int> d_vec(10);
    thrust::fill(d_vec.begin(), d_vec.end(), 7);
    thrust::sequence(d_vec.begin(), d_vec.end(), 1);
    return 0;
}
```

**Exemplo 2: Contagem Condicional**

```cpp
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/count.h>

int main() {
    thrust::device_vector<int> d_vec(10, 1);
    int count = thrust::count(d_vec.begin(), d_vec.end(), 1);
    return 0;
}
```

**Exemplo 3: Substituição Condicional**

```cpp
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/replace.h>

int main() {
    thrust::device_vector<int> d_vec(10, 1);
    thrust::replace(d_vec.begin(), d_vec.end(), 1, 2);
    return 0;
}
```

Esses exemplos mostram como usar Thrust para manipular dados eficientemente em GPUs.