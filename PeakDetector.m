re=VarName1;
im=VarName2;
% im5=(1:5);
cplx=re+im.*i;
fs=96000; %khz
% cmplx=cplx(1:5);
% plot(cplx)
y=fft(cplx);
f = (0:length(y)-1)*fs/length(y); %multiplos de 9,6 khz
n = length(cplx);                         
fshift = (-n/2:n/2-1)*(fs/n);
yshift = fftshift(y);
[peak, index]=max(abs(y))
plot(f,abs(y),'m')
% figure
% subplot(2,1,1)
% plot(f,abs(y),'m')
% % xlim([-6000 6000])
% subplot(2,1,2)
% plot(fshift,abs(yshift))
% abs(y(2605));

figure
hold on
plot(f,abs(y),fshift,abs(yshift),'.r')
plot(f(2605),abs(y(2605)),'ok')
plot(fshift(7605),abs(yshift(7605)),'sm',MarkerSize=8)
hold off

% figure
% t = (0:numel(cplx)-1)/fs;
% subplot(2,1,1)
% plot(f,abs(y))
% ylabel('signal')
% grid on
% title('Time Series')
% subplot(2,1,2)
% plot(f1,P1,'k')
% ylabel('P1')
%  temos que ((abs(y)).^2)./P1 =9.6*10^8=960000000=96000*10000
% P1=modulo da transformada/(fs*n)
[P1,f1] = periodogram(cplx,[],10000,fs,'psd');

figure
subplot(2,1,1)
hold on
plot(f1,P1) %P1 é o preto
plot(f(2605),P1(2605),'ok')
subplot(2,1,2)
hold on
plot(f,abs(y)) 
plot(f(2605),abs(y(2605)),'ok')


