# DSA mid-term Project
##### 2017170992 성인규

## linked_list.c 구현 함수 설명

### `remove_list`

parameter로 `struct linked_list* list`를 가지며, 전달된 list를 remove하는 함수이다.

크게 두 가지 경우로 나누어 처리하였다. <br>

1. `number_of_nodes`가 1 개인 경우 <br>
 첫 노드를 소멸 시킨뒤, 리스트를 삭제한다. <br> <br>
2. `number_of_nodes`가 1 개인 경우 <br> 
 `while`문을 이용해 첫 노드 부터 끝 노드까지 하나하나 소멸 시킨 뒤, 마지막으로 리스트를 삭제한다.

이때, 각 리스트의 소멸뿐만 아니라 각 노드의 소멸도 직접 따로 해주어야함을 주의하고 리스트 삭제 후, 전역 변수 `list_exist`의 값을 0으로 해주는 부분까지 해야함을 주의한다.

### `advanced_insert_node`
parameter로 `struct linked_list* list`, `struct linked_node* node`, `int nth_node`, `int start_point`를 가지며, `start_point`의 값에 따라 head나 tail 부터 n 번째 인덱스에 전달받은 노드를 삽입하는 함수이다. <br>

가장 크게는 `start_point`가 head인 경우와 tail인 경우로 나누었다. 둘 다 매우 유사한 방식으로 구현되었으므로 head의 경우를 대표적으로 살펴보겠다. <br>

이 또한 세 가지 경우로 나누었다. n이 `number_of_nodes`보다 커서 리스트의 맨 뒤에 삽입되는 경우, n이 1이라 리스트의 맨 처음에 삽입 되는 경우, 그 외의 경우(리스트의 중간). <br> 
1. `nth_node >= list->number_of_nodes` <br>
 먼저, 전달받은 노드의 `value`가 기존 노드의 `value`와 중복되는 지 확인한다. 이는 `while` 루프를 이용해 모든 노드를 순차적으로 비교하여 구현하였다. 이후, 중복이 없다면, 바로 `list->tail`의 뒤에 연결해준 이후(끝에 삽입), `list->tail`가 새 노드를 가리키게 하고 함수를 종료한다. <br> <br>
 2. `nth_node == 0`
 앞의 경우와 매우 유사하다. 다만, 이번의 경우 먼저 중복 확인을 하고 `list->head`앞에 새 노드를 연결한 후, `list->head`가 새 노드를 가리키게 하였다. <br> <br>
 3. `else`
 처음에 `while` 루프를 이용해 중복을 확인하는 동시에 기존 n 번째 인덱스 노드를 기준으로 삽입을 진행할것이기 때문에, 기존 n 번째 인덱스 노드를 찾는다. 그 이후, `list->head`로 부터 n 번째 인덱스에 삽입하는 경우 이기 때문에, 기준 노드의 앞에 새 노드를 삽입하고 함수를 종료한다. 이때 기존에 기준 노드 바로 앞의 노드의 위치를 잃지 않기 위해, 새노드를 기존의 노드에 먼저 연결해준 후, 기존 노드의 연결을 바꿔야한다. `tail`의 경우는 당연히 기준노드를 잡은 후 그 뒤에 삽입하여 준다. (n 번째 인덱스 순서 이므로)

### `remove_node`
parameter 로 `struct linked_list* list`, `int rm_node_value`를 가지며, 전달받은 값을 가진 노드를 삭제하는 함수이다.

스택형 리스트의 경우 `pop` 연산을 사용하므로, 노말 리스트만 사용할 수 있게 제한하였다. 노드의 수가 한 개일 경우, 노드 삭제후 리스트까지 삭제해야하므로, 노드의 수가 한 개인 경우를 따로 생각해 주었고, 리스트의 처음, 끝, 중간의 노드를 삭제할 때, 삭제 후 연결해주는 방법이 다 달라서 이 또한 각각 다른 세 가지의 경우로 나누었다. <br>

두 경우 모두 공통적으로, 처음에 리스트의 시작 노드부터 끝 노드까지 돌면서 삭제할 노드 값을 가진 노드를 탐색한다. 당연히 한 번 순회후에도 찾지 못한다면, 에러를 출력한다.

1. `list->number_of_nodes == 1`
 삭제할 노드(`delNode`)를 삭제 후, 리스트를 삭제한다. <br> <br>
2. `delNode == list->head`
 `list->head`를 한 칸 뒤로 옮기고 그의 `prev`가 `NULL`포인터를 가리키게 한다. 그이후 노드를 삭제한다.
3. `delNode == list->tail`
 `list->tail`을 한 칸 앞으로 옮기고 그의 `next`가 `NULL`포인터를 가리키게 한다. 그이후 노드를 삭제한다. 
4. `else`
 삭제 하기 전에 먼저 기존 노드들(삭제 노드의 전, 후 노드)의 연결을 변경해주고, 노드를 삭제한다.

 ### `push_Stack`
 parameter로 `struct linked_list* list`, `struct linked_node* node`를 가지며, parameter로 전달 받은 node를 stack list의 끝에 삽입하는 함수이다. <br>
 먼저, list의 type이 normal인 경우 에러 출력 이후, 프로그램을 종료시킨다. `push_Stack` 또한 크게 두 가지 경우로 나뉘어 구현. 총 노드의 수가 0인 경우와 그 이상인 경우로 나뉘었는데, 그 이유는 연결하는 방식이 다르기 때문이다.
 1. `list->number_of_nodes == 0`
  list의 head, tail 포인터 모두 새 노드를 가리키게 하고, 총 노드 수를 증가시킴으로 노드를 삽입시킨다.
 2. `else`
  적절한 node의 연결을 통해 기존의 마지막 노드와 연결 후, tail 포인터가 새 노드를 가리키게 한다. (이때 새 노드와 기존 꼬리 노드를 연결시키고 마지막으로 꼬리 포인터가 새 노드를 가리키게 한다.)

  ### `pop_Stack`
  parameter로 `struct linked_list* list`, `int number`를 가지며, input의 number 만큼 tail에서 부터 노드를 삭제(pop)하는 함수이다. 이때 총 노드 수와 입력의 number가 같으면, 마지막 노드 삭제 후 리스트 까지 제거한다. <br>
  따라서 이번 함수 또한, 에러를 출력하는 경우를 제외하고는 input의 number가 총 노드 수와 같은 경우, 그 외의 경우, 이렇게 두 가지 경우로 나누어 구현하였다.

  1. `list->number_of_nodes < number` 과 `number < 1`
  에러 출력.
  2. `list->number_of_nodes == number`
  `while` 루프를 이용하여 입력된 number 만큼 끝에서 부터 모든 노드를 삭제한다. (`list->tail`을 먼저 앞 노드로 옮기고 끝 노드 삭제) 이때 마지막에 노드가 하나 남은 경우, 앞 노드가 없으므로 따로 처리해준다. 모든 노드를 지운 후, 리스트도 삭제한다.
  3. `else`
  2번 에서 했던 것과 같은 방식으로 number 만큼 `while` 루프를 돌린다.

  ### `search_node`
  parameter로 `struct linked_list* list`, `int find_node_value`를 가지며, 입력된 `value`를 가지는 노드를 탐색하여 그 순서(인덱스가 아닌 순서임에 주의)를 출력하는 함수이다.<br>
  
  `while` 루프를 이용하여 처음부터 끝까지 노드를 하나하나 비교하여 선형적으로 탐색한다. 노드를 찾는 즉시 메세지를 출력하고 함수는 종료된다. 루프가 끝날때까지 함수가 종료되지 않은 경우, 찾는 노드가 함수에 존재하지 않는다는 메세지를 출력하고 프로그램을 종료시킨다.

  ### `reverse_range`
  parameter로 `struct linked_list* list`, `int order1`, `int order2` 를 가지며, order1번째 노드부터 order2번째 노드를 거꾸로 연결시키는 함수이다. 구현 시 주의할 점은 단순히 `node->value` 값만 reverse해주는 것이 아니라, 실제 노드 자체를 reverse해야한다는(기존 노드 간의 연결을 고려하여) 점이다. 기존 노드의 연결을 변경할때, head 포인터와 tail 포인터의 경우는 변경 방식이 다르기 때문에, 입력 range에 head와 tail 둘 다 포함되는 경우, head만 포함되는 경우, tail만 포함되는 경우, 둘 다 포함되지 않는 경우로 나누어 구현하였다. 둘 다 포함 되지 않는 경우부터 천천히 살펴보자. <br> <br>

  1. `else` (둘 다 포함되지 않는 경우)
  일단 `if`문으로 경우를 나누기 전, 공통적으로 order2-order1+1의 length를 갖는 `struct linked_node*` type Array를 선언해주었다. 이를 이용하여 순서를 뒤집는 방식이다. 노드를 순회하며, reverse해줘야하는 range의 시작부분 바로 앞 노드를 `preNode`로, range 끝 부분 바로 뒤 노드를 `postNode`로 할당한다. 이는 노드의 연결을 간편하게 하기위함이다. 그 후, range에 포함된 노드를 순서대로 배열에 insert한다. 순서대로 배열에 모두 담은 경우, 다시 거꾸로 꺼내어 연결해주면 된다. 따라서 또 다시 반복문을 이용해 `preNode` 부터 배열의 끝부분부터 하나하나 연결해준 뒤, 배열의 첫 노드를 `postNode`와 연결한 후 함수를 종료한다. <br>

  2. `order1 == 1` (head만 포함되는 경우)
  head가 포함되므로 `preNode`가 존재하지 않는다. 1번의 경우와 유사하게 반복문을 통해 `postNode`를 찾고 반복문 전에, 첫 노드와 끝 노드만 먼저 바꾸어 연결해주고 `list->head`도 바뀐 노드를 가리키게 한 후, 이의 `prev`가 `NULL`포인터를 가리키게한다. 이후, 남은 노드간의 연결을 반복문을 통해 연결해준다.

  3. `order2 == list->number_of_nodes` (tail만 포함되는 경우)
  이는 head와 매우 유사하지만 반대로 생각하면 된다. `preNode`만 존재하고 첫 노드와 끝 노드의 위치를 먼저 바꾼후, `list->tail`을 같은 방식으로 바꿔준다. 그 후, 남은 노드간의 연결을 반복문을 통해 연결한다.

  4. `order1==1 && order2==list->number_of_nodes` (둘 다 포함되는 경우)
  마지막으로 둘 다 포함되는 경우이다. 이는 range가 처음부터 끝까지라는 뜻이다. 따라서 head 노드와 tail 노드를 제외하고는 `reverse_range` 함수를 스스로 호출하여 reverse 시켜준다. (이 경우 `reverse_range`의 `else` 부분에서 처리되므로 문제가 되지 않는다) 그 후, `list->head`와 `list->tail` 노드만 서로 바꿔준다. 중간 노드를 함수를 통해 reverse한 후, 이 둘만 따로 처리하므로 비교적 간단하게 모든 노드의 순서를 바꿔줄 수 있다.


  ### `modify_node`
  parameter로 `struct linked_list* list`, `int modify_node_value`, `int new_value` 가지며, 입력된 `modify_node_value`를 이용해 이와 같은 값을 가지는 노드(수정할 노드)를 찾고, 찾았다면 이의 값을 `new_value`로 수정하는 함수이다.

  `search_node`와 비슷하게 반복문을 이용하여 수정할 노드를 탐색하고, 이와 동시에 `new_value`의 중복을 확인한다. 중복이 아니고 탐색에 성공한다면 그 노드의 `value`를 `new_value`로 대체한다. 

  ### `odd_sequence_reverse`
  parameter로 `struct linked_list* list` 를 가지며, 1, 3, 5 .. 이렇게 홀수 개 만큼 노드를 묶고(수가 안맞는 마지막 노드들은 다 한번에 묶음), 그 묶은 범위에서 각각 reverse 시켜주는 함수이다. 앞서 구현하였던 `reverse_range`함수를 통해 비교적 간단히 구현하였다.

  n번째 홀수의 합은 n^2 임을 이용하자. i=1 부터 시작하여 1씩 증가시키며, i^2이 총 노드의 수 보다 작은 경우 (i-1)^2 to i^2의 범위를 `reverse_range`함수를 통해 reverse한다. 그리고 i^2이 총 노드 수 이상일때 반복문을 탈출하고 마지막으로 그 전 범위의 바로 다음 노드((i-1)^2+1번째 노드)부터 마지막 노드(`list->number_of_nodes`번째 노드)까지 `reverse_range`를 통해 reverse하고 함수를 종료한다.