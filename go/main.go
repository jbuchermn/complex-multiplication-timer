package main

import (
    "fmt"
    "time"
    "os"
    "strconv"
)

func main(){
    dim,  _ := strconv.Atoi(os.Args[1])
    runs, _ := strconv.Atoi(os.Args[2])

    fmt.Printf("MATRIX MULTIPLICATION -- dim: %d, runs: %d\n",dim,runs)

    var mat = make([]complex128, dim*dim)
    var vec = make([]complex128, dim)
    var res = make([]complex128, dim)

    for i:=0; i<dim*dim; i++{
        mat[i] = complex(float64(i), 1./float64(i))
    }

    for i:=0; i<dim; i++{
        vec[i] = complex(float64(i),0.)
        res[i] = complex(0.,0.)
    }

    t_start := time.Now()

    for k:=0; k<runs; k++{
        for j:=0; j<dim; j++{
            for i:=0; i<dim; i++{
                res[i]+=mat[j*dim+i]*vec[j]
            }
        }
    }

    t_elapsed := float64(time.Since(t_start) / time.Nanosecond)

    fmt.Printf("Appc:    %9d\n",     dim*dim)
    fmt.Printf("Time:    %12.2fns\n",t_elapsed/float64(runs))
    fmt.Printf("Time/op: %12.2fns\n",t_elapsed/float64(dim*dim*runs))
}
