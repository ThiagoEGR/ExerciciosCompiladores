#include <stdio.h>

enum cat
{
	pt = 1, ptvg, eof, se, entao, senao, fim, para, ate,
	repita, id, atr, opl, nao, verd, falso, opa, opm,
	abpar, fepar, cten
};

struct token
{
	enum cat categ;
	char lex[10];
	int lin, col;

};

//Essa parte ficou ruim 
struct token tk;
struct token next();
void error(struct token tk);


void fpgm();
void flsent();
void flsentr();
void fsent();
void fsenao();
void fatr();
void fexpr();
void feb();
void febr();
void ftb();
void fea();
void fear();
void fta();
void fatr();
void ftar();
void ffa();


int main(){
	
}

struct token next()
{
	struct token tk;
    // Professor notar que essa parte tá um lixo, por que eu não fiz o analisador lexico ainda.
    return tk;
}

void error(struct token tk){
	
}

void fpgm()
{
     
     flsent();
     if (tk.categ == pt)
     {
     	next();
        if(tk.categ == eof)
        {
        	return;
        } 
        else
        {
        	puts("'EOF' ESPERADO");
        	error(tk);
        }
     }
     else
     {
     	puts("'.' ESPERADO");
     	error(tk);
     }     
}

void flsent()
{
	fsent();
	flsentr();  
}

void flsentr()
{

	if(tk.categ == ptvg)
	{
		fsent();
		flsentr();
	}

}

void fsent()
{
	tk = next();
	if (tk.categ == se)
	{
		next();
		feb();
		if(tk.categ == entao)
		{
			next();
			flsent();
			fsenao();
		}
		else
		{
			puts("'entao' esperado");
			error(tk);
		}

	}
	if (tk.categ == para)
	{
		next();
		fatr();
		if(tk.categ == ate)
		{
			next();
			fea();
			if(tk.categ == repita)
			{
				flsent();
				if(tk.categ == fim)
				{
					return;
				}
				else
				{
					puts("'fim' esperado");
					error(tk);
				}

			}
			else
			{
				puts("'repita' esperado");
				error(tk);
			}


		}
		else
		{
			puts("'ate' esperado");
			error(tk);
		}
		
	}
	else
	{
		fatr();
	}
	
}

void fsenao()
{
	if(tk.categ == fim)
	{
		next();
		return;

	}
	else if(tk.categ == senao)
	{
		next();
		flsent();
		if(tk.categ == fim)
		{
			next();
			return;
		}
		else
		{
			puts("'fim' esperado");
			error(tk);
		}


	}
	else
	{
		puts("'fim' ou 'senao' esperado");
		error(tk);
	}

}

void fexpr(){
	feb();
}

void feb()
{
	ftb();
	febr();
}

void febr()
{
	if(tk.categ == opl)
	{
        next();
        ftb();
        febr();
	}
	else
	{
		puts("'opl' esperado");
		error(tk);

	}

}

void ftb()
{
	if(tk.categ == nao){
		next();
		ftb();

	}
	else if(tk.categ == verd)
	{
		next();
		return;

	}
	else if(tk.categ == falso)
	{
		next();
		return;
	}
	else
	{
		fea();

	}

}

void fea()
{
	fta();
	fear();
}

void fear()
{
	if(tk.categ == opa)
	{
		next();
		fta();
		fear();
	}
	else
	{
		puts("'opa' esperado");
		error(tk);
	}

}

void fta()
{
	ffa();
	ftar();
}

void ftar(){
	if(tk.categ == opm){
		next();
		ffa();
		ftar();
	}
	else 
	{
		puts("'opm' esperado");
		error(tk);
	}
}

void fatr()
{
	if(tk.categ == id)
	{
         next();
         if(tk.categ == atr)
         {
         	next();
         	fexpr();
         }
         else
         {
         	puts("'=' esperado");
         	error(tk);

         }
	}
	else
	{
		puts("'id' esperado");
		error(tk);

	}

}

void ffa()
{
	if(tk.categ == abpar)
	{
		next();
		fexpr();
		if(tk.categ == fepar)
		{
			next();
			return;
		}
		else
		{
			puts("'fepar' esperado");
			error(tk);
		}
	}
	else if(tk.categ == id)
	{
		next();
		return;
	}
	else if(tk.categ == cten)
	{
		next();
		return;
	}
    
}























