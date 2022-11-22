// C言語 リスト実装サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <stdlib.h>

//ノード構造体
struct node {
	int          n   ; //値
	struct node* next; //次のノードへのポインタ
};

//新しいノードを作る
struct node* node_new(int n)
{
	struct node* this = malloc(sizeof *this);
	if (this) {
		this->n    = n   ;
		this->next = NULL;
		return this;
	}
	else {
		//メモリ割り付け失敗
		fprintf(stderr, "malloc failed.\n");
		exit(EXIT_FAILURE);
		/*NOTREACHED*/
	}
}

//ノードが抱えるデータを表示
void node_display(const struct node* this)
{
	printf("%d", this->n);
}

//リスト構造体
struct list {
	struct node* front; //先頭のノード
	struct node* back ; //末尾のノード
};

//リストのインスタンスを作る
struct list list_construct()
{
	struct list retval = { NULL };
	return retval;
}

//リストのインスタンスを破棄する
void list_destruct(struct list* this)
{
	struct node* p = this->front;
	if (p) {
		for (;;) {
			struct node* const p_next = p->next;
			free(p);
			if ((p = p_next) == NULL) {
				this->front = this->back = NULL;
				break;
			}
		}
	}
}

//リストに1要素追加
void list_push_back(struct list* this, int n)
{
	*(this->front ? &this->back->next : &this->front) = this->back = node_new(n);
}

//リストが抱えるデータを表示
void list_display(const struct list* this)
{
	const struct node* p = this->front;
	if (p) {
		node_display(p);
		while ((p = p->next) != NULL) {
			putchar('-');
			node_display(p);
		}
	}
}

//特殊要件（課題）への対応
struct list arrange(const struct list* input)
{
	const struct node* p = input->front;
	if (p) {
		struct list first  = list_construct();//奇数番目のノードをここに集める
		struct list second = list_construct();//偶数番目のノードをここに集める

		for (;;) {
			list_push_back(&first, p->n);
			if ((p = p->next) == NULL)
				break;
			else {
				list_push_back(&second, p->n);
				if ((p = p->next) == NULL)
					break;
			}
		}
		//first の後に second を連結
		first.back->next = second.front;
		first.back = second.back;
		return first;
	}
	else
		return list_construct();
}

//テスト用メイン関数
int main()
{
	struct list input = list_construct();
	list_push_back(&input, 4);
	list_push_back(&input, 2);
	list_push_back(&input, 3);
	list_push_back(&input, 8);
	list_push_back(&input, 7);
	list_push_back(&input, 1);
	list_push_back(&input, 6);
	list_push_back(&input, 9);
	fputs("入力:", stdout); list_display(&input ); putchar('\n');
	struct list output = arrange(&input);
	fputs("出力:", stdout); list_display(&output); putchar('\n');
	list_destruct(&input );
	list_destruct(&output);
	return EXIT_SUCCESS;
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q14271341894
1251463514さん

2022/11/21 15:37

0回答

C言語の問題です。以下のコードを教えてください。
リスト構造を使って、入力したリストの要素の順序を、奇数番目を前に、偶数番目を後ろに並べ替えた新たなリストを作るプログラムを作成せよ。
表示例
入力:4-2-3-8-7-1-6-9
出力:4-3-7-6-2-8-1-9
出力:

C言語関連・27閲覧
*/

//奇数番目を前に、偶数番目を後ろ
//     1 2 3 4 5 6 7 8
//入力:4-2-3-8-7-1-6-9
//出力:4-3-7-6-2-8-1-9
//
