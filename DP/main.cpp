#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include "param.h"
#include "dp.h"
#include "open_goods_list.h"

//#define DEBUG

int main(void) {
  // メモ用
  int dp[dp_num][dp_weight] = {};

  // ファイルパス
  const char file_path[256] = "C:\\Users\\momiki\\Desktop\\cpp_prac\\myDP\\param\\goods_lists.txt";
  //const char file_path[256] = "C:\\Users\\momiki\\Desktop\\cpp_prac\\myDP\\param\\param.txt";

  // アイテムリスト 0:weight 1:value
  int goods_list[max_num][elem] = {};
  char name[max_num][str_len] = {};

  // ファイルパスのファイルを一行ずつ読み込みgoods_listに格納。ファイル内の要素数を返す
  const int goods_cnt = open_goods_list(file_path, goods_list, name);

  // name_list作成
#ifdef NAME_DUMP // param.hで切替
  char name_list[dp_num][dp_weight][max_num] = {};
  // DP
  const int flg = calc_dp(dp, name_list, goods_list, goods_cnt);
#else
  const int flg = calc_dp(dp, goods_list, goods_cnt);
#endif

  printf("max val = %d\n", dp[flg][max_weight]);

#ifdef NAME_DUMP // param.hで切替
  for (int i = 0; i < goods_cnt; i++) {
    int name_list_flg = name_list[flg][max_weight][i];
    if (name_list_flg == 1) {
      printf("%s\n", name[i]);
    }
  }
#endif

  getchar();

  return 0;
}
