# DSA Project 2
##### 2017170992 성인규

## binary_search_tree.c 구현 함수 설명

### `int insertNode(char inputData)`

parameter로 `char inputData`를 가지며, 입력된 데이터를 데이터로 가지는 노드를 생성하여 BST에 삽입시키는 함수이다. 물론 `inputData`가 기존의 데이터와 중복되거나 node가 정상적으로 create되지 않은 경우 적절한 에러 메세지를 출력 후, 0을 리턴하였다. 트리가 비어있어 삽입하는 노드가 루트노드가 되는 경우와 비어있지 않은 트리에 노드를 삽입하는 경우로 나누어 삽입이 성공한 경우, 1을 리턴하고 적절한 메세지를 출력하였다.
1. 루트 노드로 삽입하는 경우 <br>
기존에 구현되어있던 `createNode` 함수를 이용해 입력된 데이터를 가지는 노드를 만들고, 이를 루트 노드 포인터가 가리키게 함으로써 삽입시킨다.
2. `else` <br>
마찬가지의 방식으로 노드를 만들어 `inputData`에 따라 적절한 위치를 찾고, parent 노드와 적절히 연결하여 삽입시켜주었다.

### `int isNodeExist(char inputData)`

parameter로 `char inputData`를 가지며, 파라미터로 입력된 data를 가지는 node가 존재하는 지를 알려주는 함수이다.
1. 노드가 존재할 시 1을 `return`한다.
2. 트리가 empty이거나 노드가 트리에 존재하지 않을 시 적절한 에러를 출력하고 0을 `return`한다.

### `treeNode findPosition(char inputData, treeNode node)`

parameter로 `char inputData`와 `treeNode node`를 가지며, 재귀적으로 입력된 데이터와 입력된 노드의 데이터를 비교하여 `inputData`를 노드를 탐색한다.
1. `inputData`를 가진 노드가 있다면 그 노드를 `return`한다.
2. `inputData`를 가진 노드가 없다면 그 노드와 가장 가까운 값을 가지는 노드를 `return` 한다.

### `int findDepth(char inputData)`

parameter로 `char inputData`를 가지며, 입력된 데이터를 가지는 노드의 depth를 리턴하는 함수이다.
1. `inputData`를 가지는 노드가 있다면 그 노드를 찾아 그 노드의 depth를 리턴한다.
2. 그 노드가 없다면 -1을 리턴한다.

### `treeNode findMin(treeNode node)`

parameter로 `treeNode node`를 가지며, 이는 입력된 노드를 루트 노드로 가지는 서브트리의 최솟값을 가지는 노드를 찾는 함수이다. 최솟값을 가지는 노드를 찾은 후, 그 노드를 리턴해준다.

### `int deleteNode(char inputData)`

parameter로 `char inputData`를 가지며, 이는 입력된 데이터를 가지는 노드를 찾아 트리에서 삭제하는 함수이다. 먼저 삭제하려는 노드가 트리에 존재하지 않는 경우 적절한 에러를 출력하며 0을 리턴하고 함수를 종료한다. 삭제할 노드를 찾은 경우, 그 노드가 몇개의 childNode를 가진지에 따라 세 가지 경우로 나누어 노드를 삭제한 후 1을 리턴한다. 또한, 1개 이하의 childNode를 가진 경우, rootNode를 삭제하는 경우도 따로 나누어 고려해주었다.
1. 삭제할 노드가 childNode가 없는 경우 <br>
삭제할 노드가 rootNode가 아니라면, 단순히 삭제할 노드가 parentNode의 leftChild 인지 rightChild 인지 확인하여 그 포인터가 `NULL`을 가리키게 하고,(연결을 끊고) 노드를 삭제한다. rootNode의 경우, 연결을 끊는 것 없이 rootNode 포인터가 `NULL`을 가리키게 한 이후, 노드를 삭제한다.

2. 삭제할 노드의 childNode가 하나인 경우 <br>
삭제할 노드가 rootNode가 아니라면, 삭제할 노드의 parent에 그 노드의 childNode를 연결시켜주고 노드를 삭제한다. rootNode의 경우 rootNode 포인터가 그 노드의 childNode를 가리키게 하고, childNode의 parent가 `NULL`을 가리키게 한 후, 노드를 삭제한다.

3. 삭제할 노드의 child노드가 2개인 경우 <br>
이 경우, 삭제할 노드가 rootNode인 지는 중요하지 않다. 먼저, 대체할 노드를 찾는다. -> BST를 inorder traverse 하여 삭제할 노드 바로 뒤에 오는 (삭제할 노드보다 크면서 그 차이가 가장 적은) 노드를 찾는다. 이 대체할 노드를 삭제하고, 원래 삭제할 노드의 데이터에 이 노드의 데이터를 assign 한다.

### `void destroyBST(void)`

parameter를 가지지 않으며, 트리 내의 모든 노드를 delete하고 트리를 destroy하는 함수이다. 트리 destory 후, 적절한 메세지를 출력하고 `void` 타입이므로 `void`값을 리턴하고 함수를 종료한다.

### `int findNode(char inputData)`

parameter로 `char inputData`를 가지며, 입력된 데이터를 가지는 노드를 찾아 그 노드의 정보(존재 여부, `parentNode`, `leftChildNode`, `rightChildNode`, `Depth`)를 출력하는 함수이다. `isNodeExist()`함수를 이용하여 존재 여부를 확인하고 없다면 에러 출력과 함께 0을 리턴하고, 존재 한다면 노드를 찾고 그 노드의 정보를 출력하며 1을 리턴하고 함수를 종료한다.

### `int treeTraversal(int traverseType, char inputData)`

parameter로 `int traverseType`과 `char inputData`를 가지며, 입력된 데이터를 가지는 노드를 찾아 그 노드를 루트 노드로하는 서브트리에 대해서 `traverseType`에 따라 세 가지 타입의 traverse를 실행하는 함수이다. 각각의 traverse 함수는 parameter로 `char inputData`를 가지며, 재귀적으로 간단하게 구현하였다. 순회 성공시 1을 실패시 에러 메세지 출력과 함께 0을 리턴해주었다. 

1. `traverseType == 0` / `preTraverse()` <br>
: `int preTraverse(char inputData)` 를 이용하여 재귀적으로 구현하였으며, 각 child 가 없을 시 고의로 적절하지 않은 데이터를 parameter로 넣어주어 함수를 종료시키도록 구현하였다. 방문한 노드의 데이터를 print함으로써 각 노드의 방문을 표현하였으며, preorder의 경우 given node(root node)를 먼저 방문 후 left -> right 임으로 코드 또한 이에 맞춰 짰다.

2. `traverseType == 1` / `inTraverse()` <br>
: 마찬가지로 `int inTraverse(char inputData)`를 이용하여 재귀적으로 구현하였으므로, 앞서 설명한 방식과 똑같은 원리로 구현하였다. 다만 inorder traverse이므로 left -> given -> right의 순으로 구현하였다.

3. `traverseType == 2` / `postTraverse()` <br>
: 이 또한 `int postTraverse(char inputData)`를 이용하여 앞서 설명한 방식과 같은 방식으로 구현하였으며, postorder이므로 left -> right -> given의 순서로 구현하였다

### `int findHeight(void)`

parameter를 가지지 않으며 BST의 총 높이를 구하는 함수이다. 배열을 만든 뒤 `int showLeaves`에서와 매우 유사한 방식으로 순서대로 노드를 넣어준다. 이때 각 레벨이 올라갈때 마다 height값을 하나씩 더해준다. 자식이 없는 leaf node 때문에 최종적으로 pop 연산을 더 이상 수행할 수 없을때 반복문을 종료하고 그때의 height값을 출력하고 리턴한다. 물론 빈 트리의 경우 -1을 리턴한다.

### `int NodeBinaryPosition(char inputData)`

parameter로 `char inputData`를 가지며, 입력된 데이터를 가지는 노드의 Postion Binary value를 출력하는 함수이다. 즉 예를 들자면, 루트 노드는 1, 루트노드의 leftChild 는 10 rightChild는 11 이런 식이다. 찾는 노드가 존재하지 않는다면 0을 리턴하고, 있다면 루트노드 부터 시작해서 left로 갈때는 0을 더하고 right로 갈때는 1을 더하는 방식으로 해서 입력 데이터를 가지는 노드를 찾은 후, 그 노드의 Postion binary value를 프린트 하고 1을 리턴하여 함수를 종료한다.

### `int showLeaves(void)`

parameter를 가지지 않으며, BST의 leaf node들을 출력하는 함수이다. 구현의 편의성을 위해 array based stack을 이용하였다. 먼저 루트 노드를 푸쉬하고 반복을 통해 pop연산을 한뒤 pop 후에 나오는 자식노드들을 푸쉬한 이후 다시 pop 연산을 수행하여 stack에 element가 없어 pop을 수행하지 못할때 까지 반복한다. 이때 pop 후에 자식노드가 하나도 없는 노드의 경우 leaf node 이므로 출력시켜준다. 트리가 비어있을 시, 0을 리턴 성공적으로 leaf node를 출력한 경우 1을 리턴한다.

### `int makeCompleteBST(void)`

parameter를 가지지 않으며, 기존의 트리에 저장된 데이터를 바탕으로 Complete Binary Search Tree 구조로 바꿔주는 함수이다. 구현 방법은 다음과 같다. 먼저, a라는 `char` 타입 배열에 기존에 있던 노드를 delete함과 각 노드의 데이터를 동시에 순서대로 저장시키고 총 노드 수를 얻는다. 이때 모든 데이터를 알고 있으므로 Complete Tree가 되는 순서로 새로 insert시켜주면 함수가 완성된다. 그의 구현은 다음과 같다.
1. 총 노드 수를 기준으로 complete BST가 완성되었을 때의 높이를 구한다. (이때, full binary tree인 경우 이후의 과정에서 편리함을 위해 원래 h에서 1을 더하여 계산한다)

2. 주어진 데이터로 complete BST가 구현이 되었을 때의 leaf 노드만 따로 빼내어 b라는 배열에 넣어준다<br>
: 이때 명칭의 편의성을 위해 leaf node라고 하였지만, 엄밀히 leaf node를 의미하는 것이 아니라, complete binary tree에서 (가장 큰 sub full binary tree를 뺀) 가장 깊은 depth의 leaf 노드들을 뜻한다. 먼저 leaf node의 수를 계산한 뒤, a의 첫번째 index에서 부터 2씩 더해가며 그 leaf node의 수 만큼 빼낸다. 이때 첫번째 index가 leaf node이고, 각 leaf node의 index가 2씩 차이나는 점은 BST를 inorder Traverse했을 때, 크기 순이라는 점을 고려하면 쉽게 알 수 있다.

3. 마찬가지로, leaf node이외의 가장 큰 sub full BST를 구성하는 데이터를 순서대로 c라는 배열에 넣어 준다. <br>
: 이때 이 노드들을 간단히 full node라고 하겠다.

4. 이제 c를 이용하여, 가장 큰 sub full BST를 만든다. <br>
: 이때 sorted array에서 binary search를 하듯이, sub array의 length가 1이 될 때까지 계속 array를 반으로 쪼개 각각의 mid값을 계산하여 `insertNode(c[mid])` 해줌으로 구현하였다. 이때, sub full BST의 크기를 알고 있으므로 단순히 몇 번 반복해줄지 계산하여 구현하였다.

5. 마지막으로 b를 이용하여, leaf node를 넣어준다. <br>
: 앞서 설명하였듯 일반적으로 이야기하는 leaf node가 아니며, leaf node가 0일 경우 아무 것도 `insert`하지 않는다.

이후 성공적으로 Complete BST를 만들었다면 1을 리턴하고 함수를 종료한다.

### `int showTree(void)`

parameter를 가지지 않으며, BST의 대략적인 구조를 출력하는 함수이다. 이 또한 array based stack를 살짝 변형한 것을 활용하여 구현하였다. 하지만, 앞선 경우들과는 다르게 `char` 타입 스택으로 스택을 초기화할때 모든 값을 `*`로 할당해주었다. 그 이후, 루트 노드부터 시작하여 데이터가 있는 index에만 그 노드의 데이터를 삽입해주고 빈 노드는 그냥 건너 뛰어준다(`*`값을 그대로 유지시킨다). 그 이후 총 출력의 수(총 노드의 수 + full binary tree의 구조를 생각할 때 빈자리의 `*`의 수)를 계산하여, 각각의 depth에 맞는 수 만큼 적절하게 출력해줌으로써 트리의 구조를 나타내었다. 처음에 h를 구할 때는 이전에 구현했었던 `findHeight()`함수를 이용 하였고 빈 트리의 경우 0을 리턴해주고, 적절하게 구조를 출력한 경우 1을 리턴하며 함수가 종료된다.  