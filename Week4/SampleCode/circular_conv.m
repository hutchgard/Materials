%% Define signals, both four points long
x_short = [1 0 .5 0];
h = [1 1 1 1];

figure(1);
subplot(2,1,1);
stem( x_short );
title('x');
axis([.75, 4.25, 0, 1.1])
subplot(2,1,2);
stem( h );
title('h');
axis([.75, 4.25, 0, 1.1])

%% Perform linear convolution

y_linear = conv(x_short, h);

figure(2);
stem(y_linear);
title('Y (linear)');
axis([.75, 7.25, 0, 1.6])

%% Perform circular convolution
X_SHORT = fft(x_short);
H = fft(h);

Y_CIRC = X_SHORT.*H;
y_circ = ifft(Y_CIRC);

figure(3);
stem(y_circ);
title( 'Y (circular)' );
axis([.75, 4.25, 0, 1.6])