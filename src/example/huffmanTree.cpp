
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Huffman树节点
struct Node
{
    char data;
    int frequency;
    Node *left;
    Node *right;

    Node(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// 用于比较节点频率的函数对象
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

// 构建Huffman树
Node *buildHuffmanTree(const string &text)
{
    // 统计字符频率
    unordered_map<char, int> frequencyMap;
    for (char c : text)
    {
        frequencyMap[c]++;
    }

    // 创建优先队列，按照频率从小到大排序
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto &pair : frequencyMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // 构建Huffman树
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

// 生成Huffman编码表
void generateHuffmanCodes(Node *root, string code, unordered_map<char, string> &huffmanCodes)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// 可视化展示Huffman树
void visualizeHuffmanTree(Node *root, int depth = 0)
{
    if (root == nullptr)
    {
        return;
    }

    visualizeHuffmanTree(root->right, depth + 1);

    for (int i = 0; i < depth; i++)
    {
        cout << "    ";
    }

    if (root->data == '$')
    {
        cout << "[$]" << endl;
    }
    else
    {
        cout << root->data << endl;
    }

    visualizeHuffmanTree(root->left, depth + 1);
}

int main()
{
    string text = "Go is expressive, concise, clean, and efficient. Its concurrency mechanisms make it easy to write programs that get the most out of multicore and networked machines, while its novel type system enables flexible and modular program construction. Go compiles quickly to machine code yet has the convenience of garbage collection and the power of run-time reflection. It's a fast, statically typed, compiled language that feels like a dynamically typed, interpreted language.!";
    Node *root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (auto &pair : huffmanCodes)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << endl
         << "Huffman Tree:" << endl;
    visualizeHuffmanTree(root);

    return 0;
    system("pause");
}
