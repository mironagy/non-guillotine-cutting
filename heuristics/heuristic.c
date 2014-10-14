#include "heuristic.h"

void run_constructive_heuristic(rectangle *pieces_cut, rectangle stock, int num_pieces_cut) {
  
  register int count_pieces;
  
  for (count_pieces = 0; count_pieces < num_pieces_cut; ++count_pieces) {
    print_rectangle(pieces_cut[count_pieces]);
  }
}


int fit_piece_stock(rectangle* stock, rectangle piece) {
  
  register int c_stock_width, c_stock_length, c_stock_local_width, c_stock_local_length;
  int fit_ok = 0;
  
  if (piece.length > stock->length || piece.width > stock->width) 
    return 0;
  
  for (c_stock_width = 0; c_stock_width <= stock->width - piece.width; ++c_stock_width) {
    
    for (c_stock_length = 0; c_stock_length <= stock->length - piece.length; ++c_stock_length) {
      
      // Verificando se a posi��o do palete j� n�o foi preenchida (ou cortada)
      if (stock->content[c_stock_width][c_stock_length] != stock->type) continue;
      
      // Verificando se o tamanho da pe�a na posi��o (c_stock_width, c_stock_length)
      // n�o excede o tamanho do palete
      if (c_stock_width + piece.width > stock->width ||
	  c_stock_length + piece.length > stock->length) continue;
      
      // Verificando se a �rea da pe�a cabe inteira numa �rea n�o-preenchida do palete
      fit_ok = 1; // supondo que a pe�a cabe
      for (c_stock_local_width = c_stock_width; (c_stock_local_width < c_stock_width + piece.width) && fit_ok; ++c_stock_local_width) {
	
	for (c_stock_local_length = c_stock_length; (c_stock_local_length < c_stock_length + piece.length) && fit_ok; ++c_stock_local_length) {
	  
	  if (stock->content[c_stock_local_width][c_stock_local_length] != stock->type) fit_ok = 0;
	}
      }
    }
  }
  
  return fit_ok;
}