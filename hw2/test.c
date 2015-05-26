
int main()
{  tree_node_t *st1, *st2, *trees[1000] ;
   int success;
   long i, j, k; 
   int  *m;
   int o[3] = {0,2,4};
   for(i=0; i<1000; i++)
      trees[i] = create_tree();
   printf("Made one thousand Trees\n");
   for(i=0; i< 100000; i++)   
   {  k = 3*i; 
      success = insert( trees[0], k, &(o[1]) ); 
      if( success != 0 )
      {  printf("  insert %d failed in tree[0], return value %d\n",k, success);
         exit(-1);
      }
   }
   for(i=0; i< 100000; i++)   
   {  k = 600000 - 3*i -3; 
      success = insert( trees[1], k, &(o[1]) ); 
      if( success != 0 )
      {  printf("  insert %d failed in tree[1], return value %d\n",k, success);
         exit(-1);
      }
   }
   k = 600000;
   for(i=2; i<999; i++)
   {  for( j=0; j<200; j++)
      {  success = insert( trees[i], k, &(o[1]) ); 
         if( success != 0 )
         {  printf("  insert %d failed in tree[%d], return value %d\n",
               k, i, success);
            exit(-1);
         }
         k +=3;
      }
   }
   for( j=0; j<100000; j++)
   {  success = insert( trees[999], k, &(o[1]) ); 
      if( success != 0 )
      {  printf("  insert %d failed in tree[999], return value %d\n",
            k, success);
         exit(-1);
      }
      k +=3;
   }
   printf("Performed %d inserts\n", k/3); fflush(stdout);
   st1 = join(trees[0], trees[1], 300000);
   
   st2 = join( st1, trees[999], 600000);
   printf("Performed two large joins\n"); fflush(stdout);
   st1 = trees[2]; k = 600600;
   for(i=3; i<999; i++)
   {  st1 = join(st1, trees[i], k);
      k+=600;
   }
   printf("Performed many small joins\n"); fflush(stdout);
   
   // st2: the join of the 3 large trees
   // st1: the join of all the 997 small trees 
   
   trees[0] = split( st2, 1000);
   trees[1] = split( st2, 600000);
   trees[0] = join( trees[0], trees[1], 1000);
   st2     = join( st1, st2, 600000 + 997*600);
   trees[0] = join( trees[0], st2, 600000);
   
   printf("Performed two splits and three more joins\n");
   for( i=0; i< 900000 + 997*600 -1; i++)
   {  m = find(trees[0],i);
      if( i%3 == 0  )
      {  if (m== NULL)
            printf(" find failed on st1 for %d, returned NULL\n", i);
         else if (*m != 2 )
            printf(" find failed on st1 for %d, returned %d instead of 2\n", i,*m );
      }
      else if (m != NULL)
            printf(" find failed on tree[0] for %d, returned non-NULL pointer\n", i);
   }
   printf("Passed %d finds. End of test.\n",900000 +997*600-2);
   fflush(stdout);
   return(0);
   
}

