      function mul(d, r) result(time)
          integer d
          integer r
          real*8 start, time

          COMPLEX*16, dimension(d,d) :: mat
          COMPLEX*16, dimension(d)   :: vec, res

          do i = 1, d
              do j=1,d
                mat(i,j)=COMPLEX(DBLE(i+j*d),1d0/DBLE(i+j*d))
              end do
              vec(i)=DBLE(i)
              res(i)=0
          end do

          call cpu_time(start)
          do i = 1,r
            res=matmul(mat,vec)
          end do
          call cpu_time(time)


          time = 1D9*(time-start)/DBLE(r)
      end function mul


      program main
          implicit none
          integer d
          integer r
          real*8 mul
          real*8 time

          character(len=8) d_, r_
          call get_command_argument(1, d_)
          call get_command_argument(2, r_)

          read(d_,'(i8)') d
          read(r_,'(i8)') r

          print *,"MATRIX MULTIPLICATION -- d=",d," r=",r
          time = mul(d,r)
          print *,"Appc:    ",d*d
          print *,"Time:    ",time
          print *,"Time/op: ",time/(d*d)
      end program main
