# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Nino Castellano

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[ ] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## Answers
1. How long did the program take with each version (You will need more than the test data)?  Describe what differences in run time you expect for your implementation. What you see in your experiments?

   > Between the two the versions of the stack, they took approximately the same run time. I expected the linked list stack to take longer since it is having to find memory in the heap. The run times were similar but with more data sets the stack based on the array would be much faster.

2. Discuss the difference in memory usage based on your implementation. You will need to think about how the versions store data.

   > The list stack used memory stored on the heap where memory addresses are scattered while the array stack uses memory on the heap but all the data is in one chunk of memory so is easier to track.

3. Which version would you use in practice. Why?

   > In practice the one that is more efficient in run time which would be the stack based on the array(vector). 

4. Make sure that your stack implementation does not have memory leaks.

   ```
==5479== HEAP SUMMARY:
==5479==     in use at exit: 0 bytes in 0 blocks
==5479==   total heap usage: 376 allocs, 376 frees, 132,372 bytes allocated
==5479==
==5479== All heap blocks were freed -- no leaks are possible
==5479==
==5479== For lists of detected and suppressed errors, rerun with: -s
==5479== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

   ```

5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   > No didn't get a chance
